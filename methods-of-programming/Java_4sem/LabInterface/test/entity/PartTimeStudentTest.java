package entity;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PartTimeStudentTest {

    @Test
    void takeDocumentsTest() {
        PartTimeStudent student = new PartTimeStudent("Viktor",2,320,"BSU","Frontend developer");
        student.takeDocumentsFromUniversity();
        assertEquals(student.getUniversityName(),"Currently not studying");
    }
    @Test
    void ApplyToUniversityTest() {
        PartTimeStudent student = new PartTimeStudent("Viktor",2,320,"BSU","Frontend developer");
        student.applyToUniversity("BSUIR");
        assertEquals(student.getUniversityName(),"BSUIR");
    }
}
