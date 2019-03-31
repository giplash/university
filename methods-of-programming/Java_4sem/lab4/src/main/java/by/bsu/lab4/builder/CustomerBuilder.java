package by.bsu.lab4.builder;

import by.bsu.lab4.entity.Customer;

import java.math.BigDecimal;

public class CustomerBuilder {

    private long id;

    private String surname;

    private String name;

    private String patronymic;

    private String address;

    private BigDecimal creditNumber;

    private BigDecimal bankNumber;

    public CustomerBuilder id(long id) {
        this.id = id;
        return this;
    }

    public CustomerBuilder surname(String surname) {
        this.surname = surname;
        return this;
    }

    public CustomerBuilder name(String name) {
        this.name = name;
        return this;
    }

    public CustomerBuilder patronymic(String patronymic) {
        this.patronymic = patronymic;
        return this;
    }

    public CustomerBuilder address(String address) {
        this.address = address;
        return this;
    }

    public CustomerBuilder creditNumber(BigDecimal creditNumber) {
        this.creditNumber = creditNumber;
        return this;
    }

    public CustomerBuilder bankNumber(BigDecimal bankNumber) {
        this.bankNumber = bankNumber;
        return this;
    }

    public Customer build() {
        return new Customer(this);
    }

    public long getId() {
        return id;
    }

    public String getSurname() {
        return surname;
    }

    public String getName() {
        return name;
    }

    public String getPatronymic() {
        return patronymic;
    }

    public String getAddress() {
        return address;
    }

    public BigDecimal getCreditNumber() {
        return creditNumber;
    }

    public BigDecimal getBankNumber() {
        return bankNumber;
    }
}
