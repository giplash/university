package by.bsu.lab2.action;

import by.bsu.lab2.constants.ErrorMessages;
import by.bsu.lab2.constants.MatrixConstants;
import by.bsu.lab2.exceptions.MatrixIllegalIndexException;
import by.bsu.lab2.exceptions.MatrixIllegalSizeException;
import java.util.Random;

/**
 * Класс для работы с матрицей
 */
public class Matrix {

    private final int rowsCount;
    private final int columnsCount;
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
        this.rowsCount = rowsCount;
        this.columnsCount = columnsCount;
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
        this(MatrixConstants.DEFAULT_ROWS_COUNT, MatrixConstants.DEFAULT_COLUMNS_COUNT);
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
        return rowsCount;
    }

    /**
     * Метод, возвращающий количество столбцов матрицы
     * @return количество столбцов матрицы
     */
    public int getColumnsCount() {
        return columnsCount;
    }

    /**
     * Метод, возвращающий элемент матрицы по его индексу
     * @param rowIndex индекс строки
     * @param columnIndex индекс столбца
     * @return искомый элемент матрицы
     */
    public int getElement(int rowIndex, int columnIndex) throws MatrixIllegalIndexException {
        if (!MatrixValidator.isCorrectIndexes(rowIndex, columnIndex, this.rowsCount, this.columnsCount)) {
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
        if (!MatrixValidator.isCorrectIndex(rowIndex, this.rowsCount)) {
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
        if (!MatrixValidator.isCorrectIndex(columnIndex, this.columnsCount)) {
            throw new MatrixIllegalIndexException(ErrorMessages.INCORRECT_INDEX);
        }
        int[] column = new int[this.rowsCount];
        for (int i = 0; i < this.rowsCount; i++) {
            column[i] = this.matrix[i][columnIndex];
        }
        return column;
    }

    /**
     * Метод, заполняющий матрицу определенным числом
     * @param element число, которым будет заполнена матрица
     */
    public void fill(int element) {
        for (int i = 0; i < this.rowsCount; i++) {
            for (int j = 0; j < this.columnsCount; j++) {
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
        for (int i = 0; i < this.rowsCount; i++) {
            for (int j = 0; j < this.columnsCount; j++) {
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
        for (int i = 0; i < this.rowsCount; i++) {
            for (int j = 0; j < this.columnsCount; j++) {
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
        for (int i = 0; i < this.rowsCount; i++) {
            for (int j = 0; j < this.columnsCount; j++) {
                res += this.matrix[i][j] + " ";
            }
            res += '\n';
        }
        return res;
    }
}
