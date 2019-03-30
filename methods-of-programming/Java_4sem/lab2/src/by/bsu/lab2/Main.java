package by.bsu.lab2;

import by.bsu.lab2.action.MatrixFiller;
import by.bsu.lab2.entity.Matrix;
import by.bsu.lab2.action.MatrixShifter;
import by.bsu.lab2.exceptions.MatrixIllegalIndexException;
import by.bsu.lab2.exceptions.MatrixIllegalSizeException;


/**
 * Точка входа в программу, где происходит проверка работоспособности классов
 */
public class Main {

    public static void main(String[] args) {

        // Создаем матрицу 3х3, проверяем корректность работы
        try {
            Matrix matrix = new Matrix(3, 3);
            MatrixFiller.fillRandom(matrix, 5);
            System.out.println("Matrix before shifting:");
            System.out.println(matrix.toString());

            MatrixShifter.shift("right", matrix, 1);
            System.out.println("Shift matrix to the right for 1 step:");
            System.out.println(matrix.toString());

            MatrixShifter.shift("top", matrix, 2);
            System.out.println("Shift matrix to the top for 2 steps:");
            System.out.println(matrix.toString());
        } catch (Exception exception) {
            System.out.println('h');
        }

        // Проверяем ошибку на неправильный размер матрицы
        try {
            Matrix matrix = new Matrix(-1, 3);
        } catch (MatrixIllegalSizeException exception) {
            System.out.println("Exception is caught:");
            System.out.println(exception.getMessage());
        }

        // Проверяем ошибку на получение неправильного элемента матрицы
        try {
            Matrix matrix = new Matrix(3, 3);
            MatrixFiller.fillRandom(matrix, 10);
            matrix.getElement(-1, 0);
        } catch (MatrixIllegalIndexException exception) {
            System.out.println("Exception is caught:");
            System.out.println(exception.getMessage());
        } catch (MatrixIllegalSizeException exception) {
        }
    }
}
