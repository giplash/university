package by.bsu.lab4.entity;

import by.bsu.lab4.builder.CustomerBuilder;
import org.apache.log4j.Logger;

import java.io.Serializable;
import java.math.BigDecimal;

public class Customer implements Serializable, Comparable<Customer> {

    private transient static final Logger logger = Logger.getLogger(Customer.class);

    private long id;

    private String surname;

    private String name;

    private String patronymic;

    private String address;

    private BigDecimal creditNumber;

    private BigDecimal bankNumber;

    public Customer(CustomerBuilder customerBuilder) {
        this.id = customerBuilder.getId();
        this.surname = customerBuilder.getSurname();
        this.name = customerBuilder.getName();
        this.patronymic = customerBuilder.getPatronymic();
        this.address = customerBuilder.getAddress();
        this.creditNumber = customerBuilder.getCreditNumber();
        this.bankNumber = customerBuilder.getBankNumber();
        logger.info("A new customer " + this + " was created!");
    }

    public static Logger getLogger() {
        return logger;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public void setPatronymic(String patronymic) {
        this.patronymic = patronymic;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public BigDecimal getCreditNumber() {
        return creditNumber;
    }

    public void setCreditNumber(BigDecimal creditNumber) {
        this.creditNumber = creditNumber;
    }

    public BigDecimal getBankNumber() {
        return bankNumber;
    }

    public void setBankNumber(BigDecimal bankNumber) {
        this.bankNumber = bankNumber;
    }

    @Override
    public int compareTo(Customer customer) {
        return this.surname.compareTo(customer.getSurname());
    }

    @Override
    public String toString() {
        return "Customer{" +
                "id=" + id +
                ", surname='" + surname + '\'' +
                ", name='" + name + '\'' +
                ", patronymic='" + patronymic + '\'' +
                ", address='" + address + '\'' +
                ", creditNumber='" + creditNumber + '\'' +
                ", bankNumber='" + bankNumber + '\'' +
                '}';
    }
}
