package by.bsu.lab2.action;

import by.bsu.lab2.constants.Directions;
import by.bsu.lab2.exceptions.MatrixIllegalIndexException;

/**
 * Класс для работы с со сдвигами матрицы
 */
public class MatrixShifter {

    /**
     * Метод для сдвига матрицы влево
     * @param matrix матрица
     * @param steps количество шагов
     */
    public static void shiftLeft(Matrix matrix, int steps) {
        try {
            int rowsCount = matrix.getRowsCount();
            int columnsCount = matrix.getColumnsCount();
            for (int i = 0; i < rowsCount; i++) {
                int realSteps = steps % columnsCount;
                while (realSteps-- > 0) {
                    int temp = matrix.getElement(i, 0);
                    for (int j = columnsCount - 1; j >= 0; j--) {
                        int val = matrix.getElement(i, j);
                        matrix.setElement(temp, i, j);
                        temp = val;
                    }
                }
            }
        } catch (MatrixIllegalIndexException exception) {
        }
    }

    /**
     * Метод для сдвига матрицы вправо
     * @param matrix матрица
     * @param steps количество шагов
     */
    public static void shiftRight(Matrix matrix, int steps) {
        try {
            int rowsCount = matrix.getRowsCount();
            int columnsCount = matrix.getColumnsCount();
            for (int i = 0; i < rowsCount; i++) {
                int realSteps = steps % columnsCount;
                while (realSteps-- > 0) {
                    int temp = matrix.getElement(i, columnsCount - 1);
                    for (int j = 0; j < columnsCount; j++) {
                        int val = matrix.getElement(i, j);
                        matrix.setElement(temp, i, j);
                        temp = val;
                    }
                }
            }
        } catch (MatrixIllegalIndexException exception) {
        }
    }

    /**
     * Метод для сдвига матрицы вниз
     * @param matrix матрица
     * @param steps количество шагов
     */
    public static void shiftDown(Matrix matrix, int steps) {
        try {
            int rowsCount = matrix.getRowsCount();
            int columnsCount = matrix.getColumnsCount();
            for (int j = 0; j < columnsCount; j++) {
                int realSteps = steps % rowsCount;
                while (realSteps-- > 0) {
                    int temp = matrix.getElement(rowsCount - 1, j);
                    for (int i = 0; i < rowsCount; i++) {
                        int val = matrix.getElement(i, j);
                        matrix.setElement(temp, i, j);
                        temp = val;
                    }
                }
            }
        } catch (MatrixIllegalIndexException exception) {
        }
    }

    /**
     * Метод для сдвига матрицы вверх
     * @param matrix матрица
     * @param steps количество шагов
     */
    public static void shiftUp(Matrix matrix, int steps) {
        try {
            int rowsCount = matrix.getRowsCount();
            int columnsCount = matrix.getColumnsCount();
            for (int j = 0; j < columnsCount; j++) {
                int realSteps = steps % rowsCount;
                while (realSteps-- > 0) {
                    int temp = matrix.getElement(0, j);
                    for (int i = rowsCount - 1; i >= 0; i--) {
                        int val = matrix.getElement(i, j);
                        matrix.setElement(temp, i, j);
                        temp = val;
                    }
                }
            }
        } catch (MatrixIllegalIndexException exception) {
        }
    }

    /**
     * Метод для сдвига матрицы в направлении, завясящем от параметра
     * @param direction направление в виде строки
     * @param matrix матрица
     * @param steps количество шагов
     */
    public static void shift(String direction, Matrix matrix, int steps) {
        switch (direction) {
            case Directions.LEFT:
                shiftLeft(matrix, steps);
                break;
            case Directions.RIGHT:
                shiftRight(matrix, steps);
                break;
            case Directions.UP:
                shiftUp(matrix, steps);
                break;
            case Directions.DOWN:
                shiftDown(matrix, steps);
                break;
        }
    }
}
