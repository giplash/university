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
        assertEquals("123фыва", mapper.replace("123фыва"));
    }

    @Test
    public void shouldWorksWithAndWithoutEnglishLetters() {
        LetterMapper mapper = new LetterMapper();
        assertEquals("123фыва123", mapper.replace("123фываABC"));
    }

    @Test
    public void shouldWorksWithFullEnglishAlphabet() {
        LetterMapper mapper = new LetterMapper();
        assertEquals(
                "12345678910111213141516171819202122232425261234567891011121314151617181920212223242526",
                mapper.replace("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
        );
    }
}
