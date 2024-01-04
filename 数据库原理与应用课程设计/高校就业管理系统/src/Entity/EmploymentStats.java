package Entity;

public class EmploymentStats {
  public   int GraduationCount;
    public   int UnemployedCount;
    public   int EmployedCount;
    public int EmploymentRate;

    public EmploymentStats(int graduationCount, int unemployedCount, int employedCount, int employmentRate) {
        GraduationCount = graduationCount;
        UnemployedCount = unemployedCount;
        EmployedCount = employedCount;
        EmploymentRate = employmentRate;
    }
}
