from http import cookies
from bs4 import BeautifulSoup
from weasyprint import HTML
import re
import requests
import os

# 课程 ID （链接里 /course/ 后面那个数）
course_id =

# 要生成的第一个卷的卷号
begin_volume_id = 
# 要生成的最后一个卷的卷号
end_volume_id = 

# cookie 换成自己的
cookies = {
    "csrftoken": "",
    "sessionid": "",
}

result_AC_pattern = re.compile(r".*userprofile=\d+&result=AC")


def parse_volume(volume_id):
    url = f"http://10.132.246.246/course/{course_id}/volume/{volume_id}/detail/"

    response = requests.get(url, cookies=cookies)

    html_content = response.text

    soup = BeautifulSoup(html_content, "lxml")

    div_span12 = soup.find("div", class_="span12")
    td_center = div_span12.find("td", attrs={"align": "center"})

    volume_name = td_center.text

    judgelist_links = []

    for a_tag in soup.find_all("a"):
        href = a_tag.get("href", "")
        if result_AC_pattern.match(href):
            judgelist_links.append("http://10.132.246.246" + href)

    return volume_name, judgelist_links


judge_course_pattern = re.compile(r"/judge/\d+/course/\d+/")


def parse_judgelist(judgelist_link):
    response = requests.get(judgelist_link, cookies=cookies)

    html_content = response.text

    soup = BeautifulSoup(html_content, "lxml")

    judge_links = []

    for a_tag in soup.find_all("a"):
        href = a_tag.get("href", "")
        if judge_course_pattern.match(href):
            judge_links.append("http://10.132.246.246" + href)

    return judge_links[0]


def render_page(exp_link, dir):
    response = requests.get(exp_link, cookies=cookies)

    html_content = response.text

    soup = BeautifulSoup(html_content, "lxml")

    title = soup.title.string.strip().replace(":", "_")

    HTML(string=html_content).write_pdf(dir + title + ".pdf")

    print(dir + title + ".pdf 生成成功")


def generate_for_volume(volume_id):
    volume_name, judgelist_links = parse_volume(volume_id)
    try:
        os.mkdir(volume_name)
        print(f"文件夹 '{volume_name}' 创建成功。")
    except FileExistsError:
        print(f"文件夹 '{volume_name}' 已存在。")
    except OSError as error:
        print(f"创建文件夹时发生错误: {error}")
    for judgelist_link in judgelist_links:
        exp_link = parse_judgelist(judgelist_link) + "print_ass/"
        render_page(exp_link, volume_name + "/")


for i in range(begin_volume_id, end_volume_id + 1):
    generate_for_volume(i)
