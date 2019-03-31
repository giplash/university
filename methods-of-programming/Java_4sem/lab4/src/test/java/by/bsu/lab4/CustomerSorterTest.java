package by.bsu.lab4;

import by.bsu.lab4.builder.CustomerBuilder;
import by.bsu.lab4.entity.Customer;
import by.bsu.lab4.util.CustomerSorter;
import org.junit.Test;

import java.math.BigDecimal;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class CustomerSorterTest {

    Customer customer1 = new CustomerBuilder()
                                .id(1)
                                .surname("Anashkin")
                                .name("Victor")
                                .patronymic("Andreevich")
                                .address("Moskovskaya 16, kv 386")
                                .creditNumber(new BigDecimal("1111222233334444"))
                                .bankNumber(new BigDecimal("1234567890000000"))
                                .build();

    Customer customer2 = new CustomerBuilder()
                                .id(2)
                                .surname("Azarov")
                                .name("Vlad")
                                .patronymic("Alekseevich")
                                .address("Leningradskaya 17, kv 340")
                                .creditNumber(new BigDecimal("2113222533334444"))
                                .bankNumber(new BigDecimal("4136577890000000"))
                                .build();

    List<Customer> customers = Arrays.asList(customer2, customer1);

    CustomerSorter customerSorter = new CustomerSorter();

    @Test
    public void sortCustomersBySurname() {
        List<Customer> expected = Arrays.asList(customer1, customer2);
        assertEquals(expected, customerSorter.sortCustomersBySurname(customers));
    }
}
