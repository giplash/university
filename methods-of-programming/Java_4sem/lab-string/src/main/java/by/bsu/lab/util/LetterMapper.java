package by.bsu.lab.util;


public class LetterMapper {

    public String replace(String string) {
        char[] array = string.toCharArray();
        String result = "";

        for (int i = 0; i < array.length; i++) {
            result += (mapLetterToAplhabetic(array[i]));
        }

        return result;
    }

    private String mapLetterToAplhabetic(char letter) {
        LetterHelper hepler = new LetterHelper();
        if (!hepler.isLetter(letter)) {
            return String.valueOf(letter);
        }
        int code = (int)letter;
        int lowercase = 64;
        int uppercase = 96;
        if (hepler.isLowercaseLetter(letter)) {
            return String.valueOf(code - lowercase);
        } else {
            return String.valueOf(code - uppercase);
        }
    }
}
