package entity;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Objects;
import java.util.StringJoiner;

public class PartTimeStudent extends Student {
    private static final Logger LOGGER = LogManager.getLogger(PartTimeStudent.class);
    public String jobName;


    public PartTimeStudent(String name, int group, int examMark, String universityName, String jobName) {
        super(name, group, examMark, universityName);
        this.jobName = jobName;
        LOGGER.info("Part time student created: "+ this.toString());
    }

    public String getJobName() {
        return jobName;
    }

    public void setJobName(String jobName) {
        this.jobName = jobName;
    }
    public void applyToUniversity(String universityName) {
        this.setUniversityName(universityName);
    }
    public void takeDocumentsFromUniversity() {
        this.setUniversityName("Currently not studying");
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        PartTimeStudent student = (PartTimeStudent) o;
        return Objects.equals(jobName, student.jobName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), jobName);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", PartTimeStudent.class.getSimpleName() + "[", "]")
                .add("jobName='" + jobName + "'")
                .toString()+super.toString();
    }
}
