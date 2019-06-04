package by.bsu.lab.util;

public class LetterHelper {

    public boolean isLetter(char letter) {
        return isLowercaseLetter(letter) || isUppercaseLetter(letter);
    }

    public boolean isLowercaseLetter(char letter) {
        int code = (int)letter;
        return (code <= 90 & code >= 65);
    }

    public boolean isUppercaseLetter(char letter) {
        int code = (int)letter;
        return (code <=122 & code >= 97);
    }
}
