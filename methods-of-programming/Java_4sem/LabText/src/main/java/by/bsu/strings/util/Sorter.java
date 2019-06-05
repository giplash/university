package by.bsu.strings.util;

import java.util.*;
import java.util.stream.Collectors;

public class Sorter {

    public String sortText(String text) {
        StringBuilder res = new StringBuilder();
        List<String> sentences = Spliter.getSentencesByText(text);
        Map<String, Integer> map = new HashMap<>();
        sentences.forEach(sentence -> {
            Integer wordsCount = Spliter.getPartsByDelimiter(sentence,"[,;:.!?\\s]+").size();
            map.put(sentence, wordsCount);
        });
        Set<Map.Entry<String, Integer>> entrySet = map.entrySet();
        sentences = entrySet.stream()
                    .sorted((entry1, entry2) -> entry1.getValue() - entry2.getValue())
                    .map(entry -> entry.getKey())
                    .collect(Collectors.toList());
        sentences.forEach(sentence -> res.append(sentence));
        return res.toString();
    }

}
