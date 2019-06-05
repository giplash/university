package by.bsu.strings.util;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Spliter {

    public static List<String> getPartsByDelimiter(String text, String delimter) {
        return Arrays.asList(text.split(delimter));
    }

    public static List<String> getSentencesByText(String text) {
        List<String> delimiters = Spliter.getDelimitersByText(text);
        List<String> sentences = Arrays.asList(text.split("[.!?]\\s*"));
        List<String> res = new ArrayList<>();
        for (int i = 0; i < sentences.size(); i++) {
            res.add(sentences.get(i) + delimiters.get(i));
        }
        return res;
    }

    private static List<String> getDelimitersByText(String text) {
        List<String> delimiters = new ArrayList<>();
        Pattern pattern = Pattern.compile("[.!?]\\s*");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            delimiters.add(matcher.group());
        }
        return delimiters;
    }

}
