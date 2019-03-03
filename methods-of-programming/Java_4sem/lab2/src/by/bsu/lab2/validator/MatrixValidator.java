package by.bsu.lab2.validator;

/**
 * Класс для проверки корректности данных матрицы
 */
public class MatrixValidator {

    /**
     * Метод для проверки корректности размерности матрицы
     * @param rowsCount количество строк
     * @param columnsCount количество столбцов
     * @return true, если все корректно, иначе - false
     */
    public static boolean isCorrectSize(int rowsCount, int columnsCount) {
        return rowsCount > 0 && columnsCount > 0;
    }

    /**
     * Метод для проверки корректности индекса элемента матрицы
     * @param rowIndex индекс строки
     * @param columnIndex индекс столбца
     * @param rowsCount количество строк
     * @param columnsCount количество столбцов
     * @return true, если все корректно, иначе - false
     */
    public static boolean isCorrectIndexes(int rowIndex, int columnIndex, int rowsCount, int columnsCount) {
        return rowIndex >= 0 && rowIndex < rowsCount && columnIndex < columnsCount && columnIndex >= 0;
    }

    /**
     * Метод для проверки корректности индекса строки или столбца матрицы
     * @param index индекс строки или столбца
     * @param rowsOrColumnsCount количество строк или столбцов матрциы
     * @return true, если все корректно, иначе - false
     */
    public static boolean isCorrectIndex(int index, int rowsOrColumnsCount) {
        return index >= 0 && index < rowsOrColumnsCount;
    }
}
