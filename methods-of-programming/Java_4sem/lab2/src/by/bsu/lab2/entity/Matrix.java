package by.bsu.lab2.entity;

import by.bsu.lab2.validator.MatrixValidator;
import by.bsu.lab2.constant.ErrorMessages;
import by.bsu.lab2.constant.MatrixConstant;
import by.bsu.lab2.exceptions.MatrixIllegalIndexException;
import by.bsu.lab2.exceptions.MatrixIllegalSizeException;
import java.util.Random;

/**
 * Класс для работы с матрицей
 */
public class Matrix {

    private int[][] matrix;

    /**
     * Конструктор, задающий размеры матрицы по параметрам
     * @param rowsCount количество строк
     * @param columnsCount количество столбцов
     */
    public Matrix(int rowsCount, int columnsCount) throws MatrixIllegalSizeException {
        if (!MatrixValidator.isCorrectSize(rowsCount, columnsCount)) {
            throw new MatrixIllegalSizeException(ErrorMessages.INCORRECT_SIZE);
        }
        this.matrix = new int[rowsCount][columnsCount];
    }

    /**
     * Конструктор, задающий размеры матрицы по параметру
     * @param size количество строк и столбцов
     */
    public Matrix(int size) throws MatrixIllegalSizeException {
        this(size, size);
    }

    /**
     * Конструктор, задающий размеры матрицы по параметрам по умолчанию
     */
    public Matrix() throws MatrixIllegalSizeException {
        this(MatrixConstant.DEFAULT_ROWS_COUNT, MatrixConstant.DEFAULT_COLUMNS_COUNT);
    }

    /**
     * Метод, устанавливающие значение элемента матрицы по индексу
     * @param value устанавливаемое значение элемента
     * @param rowIndex индекс строки
     * @param columnIndex индекс столбца
     */
    public void setElement(int value, int rowIndex, int columnIndex) {
        this.matrix[rowIndex][columnIndex] = value;
    }

    /**
     * Метод, возвращающий количество строк матрицы
     * @return количество строк матрицы
     */
    public int getRowsCount() {
        return matrix.length;
    }

    /**
     * Метод, возвращающий количество столбцов матрицы
     * @return количество столбцов матрицы
     */
    public int getColumnsCount() {
        return matrix[0].length;
    }

    /**
     * Метод, возвращающий элемент матрицы по его индексу
     * @param rowIndex индекс строки
     * @param columnIndex индекс столбца
     * @return искомый элемент матрицы
     */
    public int getElement(int rowIndex, int columnIndex) throws MatrixIllegalIndexException {
        if (!MatrixValidator.isCorrectIndexes(rowIndex, columnIndex, getRowsCount(), getColumnsCount())) {
            throw new MatrixIllegalIndexException(ErrorMessages.INCORRECT_INDEX);
        }
        return this.matrix[rowIndex][columnIndex];
    }

    /**
     * Метод, возвращающий строку матрицы по ее индексу
     * @param rowIndex индекс строки
     * @return строку в виде массива int[]
     */
    public int[] getRow(int rowIndex) throws MatrixIllegalIndexException {
        if (!MatrixValidator.isCorrectIndex(rowIndex, getRowsCount())) {
            throw new MatrixIllegalIndexException(ErrorMessages.INCORRECT_INDEX);
        }
        return this.matrix[rowIndex];
    }

    /**
     * Метод, возвращающий стобец матрицы по его индексу
     * @param columnIndex индекс столбца
     * @return стобец в виде массива int[]
     */
    public int[] getColumn(int columnIndex) throws MatrixIllegalIndexException {
        if (!MatrixValidator.isCorrectIndex(columnIndex, getColumnsCount())) {
            throw new MatrixIllegalIndexException(ErrorMessages.INCORRECT_INDEX);
        }
        int[] column = new int[getRowsCount()];
        for (int i = 0; i < getRowsCount(); i++) {
            column[i] = this.matrix[i][columnIndex];
        }
        return column;
    }

    /**
     * Метод, заполняющий матрицу определенным числом
     * @param element число, которым будет заполнена матрица
     */
    public void fill(int element) {
        for (int i = 0; i < getRowsCount(); i++) {
            for (int j = 0; j < getColumnsCount(); j++) {
                matrix[i][j] = element;
            }
        }
    }

    /**
     * Метод, заполняющий матрицу произвольными числами
     * @param upperBound верхняя граница произвольного числа
     */
    public void fillRandom(int upperBound) {
        Random rand = new Random();
        for (int i = 0; i < getRowsCount(); i++) {
            for (int j = 0; j < getColumnsCount(); j++) {
                matrix[i][j] = rand.nextInt(upperBound);
            }
        }
    }

    /**
     * Метод, проверяющий, присутствует ли определенный элемент в матрице
     * @param element элемент, наличие которого проверяется
     * @return true если элемент найден, иначе - false
     */
    public boolean includes(int element) {
        for (int i = 0; i < getRowsCount(); i++) {
            for (int j = 0; j < getColumnsCount(); j++) {
                if (matrix[i][j] == element) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Метедо, приводящий матрицу к строке
     * @return матрице в виде строки (между элементами строки пробем, между строками - перенос строки)
     */
    public String toString() {
        String res = "";
        for (int i = 0; i < getRowsCount(); i++) {
            for (int j = 0; j < getColumnsCount(); j++) {
                res += this.matrix[i][j] + " ";
            }
            res += '\n';
        }
        return res;
    }
}
