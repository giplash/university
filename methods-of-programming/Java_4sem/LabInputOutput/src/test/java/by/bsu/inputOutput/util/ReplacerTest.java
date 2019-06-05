package by.bsu.inputOutput.util;

import org.junit.Test;

import java.io.File;

import static org.junit.Assert.assertEquals;

public class ReplacerTest {

    Replacer replacer = new Replacer();

    Reader reader = new Reader();

    File file = new File("src/main/resources/class.txt");

    String text = "class Main {\n" +
            "    private int age;\n" +
            "    private String name;\n" +
            "    private static void main(String args[]) {\n" +
            "    }\n" +
            "    private void hello() {}\n" +
            "}\n";

    @Test
    public void replacePublicToPrivateTest() {
        String temp = reader.getTextFromFile(file);
        String actual = replacer.replacePublicToPrivate(temp);
        assertEquals(text, actual);
    }
}
