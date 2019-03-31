package by.bsu.lab4.util;

import by.bsu.lab4.entity.Customer;

import java.util.List;
import java.util.stream.Collectors;

public class CustomerSorter {

    public List<Customer> sortCustomersBySurname(List<Customer> customers) {
        return customers.parallelStream()
                            .sorted(Customer::compareTo)
                            .collect(Collectors.toList());
    }
}
