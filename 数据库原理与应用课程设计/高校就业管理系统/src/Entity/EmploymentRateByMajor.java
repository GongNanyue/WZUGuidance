package Entity;

public class EmploymentRateByMajor {
    public String Major;
    public int TotalGraduates;
    public int EmployedCount;
    public int EmploymentRate;

    public EmploymentRateByMajor(String major, int totalGraduates, int employedCount, int employmentRate) {
        Major = major;
        TotalGraduates = totalGraduates;
        EmployedCount = employedCount;
        EmploymentRate = employmentRate;
    }
}
