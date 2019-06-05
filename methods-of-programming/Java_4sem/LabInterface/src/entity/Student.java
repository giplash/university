package entity;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Objects;
import java.util.StringJoiner;

public abstract class Student implements Abiturient {
    private static final Logger LOGGER = LogManager.getLogger(Student.class);
    private String name;
    private int group;
    private int examMark;
    private String universityName;

    protected Student(String name, int group, int examMark, String universityName) {
        this.name = name;
        this.group = group;
        this.examMark = examMark;
        this.universityName = universityName;
        LOGGER.info("Student info: Name " + name + " Group " + group +" Exam mark "+ examMark + " University " + universityName);
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getGroup() {
         return group;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public int getExamMark() {
        return examMark;
    }

    public void setExamMark(int examMark) {
        this.examMark = examMark;
    }
    public String getUniversityName() {
        return universityName;
    }

    public void setUniversityName(String universityName) {
        this.universityName = universityName;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return group == student.group &&
                examMark == student.examMark &&
                name.equals(student.name) &&
                universityName.equals(student.universityName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, group, examMark, universityName);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", Student.class.getSimpleName() + "[", "]")
                .add("name='" + name + "'")
                .add("group=" + group)
                .add("examMark=" + examMark)
                .add("universityName='" + universityName + "'")
                .toString();
    }
}
