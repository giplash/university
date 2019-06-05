package by.bsu.inputOutput.util;

import java.io.*;

public class Writer {

    public void writeTextToFile(File file, String text) {
        try (FileWriter fileWriter = new FileWriter(file);
                BufferedWriter bufferedWriter = new BufferedWriter(fileWriter)) {
            bufferedWriter.write(text);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
