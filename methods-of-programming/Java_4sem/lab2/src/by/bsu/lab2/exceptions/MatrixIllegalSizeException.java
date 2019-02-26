package by.bsu.lab2.exceptions;

/**
 * Класс исключение для неправильного размера матрицы
 */
public class MatrixIllegalSizeException extends Exception {

    public MatrixIllegalSizeException() {
        super();
    }

    public MatrixIllegalSizeException(String message) {
        super(message);
    }

    public MatrixIllegalSizeException(String message, Throwable throwable) {
        super(message, throwable);
    }

    public MatrixIllegalSizeException(Throwable throwable) {
        super(throwable);
    }
}
