package by.bsu.lab2.action;

import by.bsu.lab2.entity.Matrix;
import by.bsu.lab2.exceptions.MatrixIllegalIndexException;

import java.util.Random;


/**
 * Класс для заполнения матриц элементами
 */
public class MatrixFiller {

    /**
     * Метод, заполняющий матрицу определенным числом
     * @param matrix матрица, которую нужно заполнять
     * @param element число, которым будет заполнена матрица
     */
    public static void fill(Matrix matrix, int element) throws MatrixIllegalIndexException {
        for (int i = 0; i < matrix.getRowsCount(); i++) {
            for (int j = 0; j < matrix.getColumnsCount(); j++) {
                matrix.setElement(element, i, j);
            }
        }
    }

    /**
     * Метод, заполняющий матрицу произвольными числами
     * @param matrix матрица, которую нужно заполнять
     * @param upperBound верхняя граница произвольного числа
     */
    public static void fillRandom(Matrix matrix, int upperBound) throws MatrixIllegalIndexException {
        Random rand = new Random();
        for (int i = 0; i < matrix.getRowsCount(); i++) {
            for (int j = 0; j < matrix.getColumnsCount(); j++) {
                matrix.setElement(rand.nextInt(upperBound), i, j);
            }
        }
    }
}
