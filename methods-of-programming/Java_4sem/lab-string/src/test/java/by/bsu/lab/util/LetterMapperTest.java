package by.bsu.lab.util;

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class LetterMapperTest {

    @Test
    public void shouldWorksWithEmptyString() {
        LetterMapper mapper = new LetterMapper();
        assertEquals("", mapper.replace(""));
    }

    @Test
    public void shouldWorksWithoutEnglishLetters() {
        LetterMapper mapper = new LetterMapper();
        assertEquals("1 2 3 ф ы в а ", mapper.replace("123фыва"));
    }

    @Test
    public void shouldWorksWithEnglishLetters() {
        LetterMapper mapper = new LetterMapper();
        assertEquals("1 2 3 ф ы в а 1 2 3 ", mapper.replace("abcфываABC"));
    }

    @Test
    public void shouldWorksWithFullEnglishAlphabet() {
        LetterMapper mapper = new LetterMapper();
        assertEquals(
                "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 ",
                mapper.replace("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        );
    }
}
