package by.bsu.lab2.exceptions;

/**
 * Класс исключение для неправильного индекса в матрице
 */
public class MatrixIllegalIndexException extends Exception {

    public MatrixIllegalIndexException() {
        super();
    }

    public MatrixIllegalIndexException(String message) {
        super(message);
    }

    public MatrixIllegalIndexException(String message, Throwable throwable) {
        super(message, throwable);
    }

    public MatrixIllegalIndexException(Throwable throwable) {
        super(throwable);
    }
}