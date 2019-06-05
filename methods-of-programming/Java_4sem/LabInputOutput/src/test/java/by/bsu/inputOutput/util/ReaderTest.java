package by.bsu.inputOutput.util;

import org.junit.Test;

import java.io.File;

import static org.junit.Assert.assertEquals;

public class ReaderTest {

    Reader reader = new Reader();

    File file = new File("src/main/resources/class.txt");

    String text = "class Main {\n" +
            "    public int age;\n" +
            "    public String name;\n" +
            "    public static void main(String args[]) {\n" +
            "    }\n" +
            "    public void hello() {}\n" +
            "}\n";
    @Test
    public void getTextFromFileTest() {
        String result = reader.getTextFromFile(file);
        assertEquals(text, result);
    }
}
