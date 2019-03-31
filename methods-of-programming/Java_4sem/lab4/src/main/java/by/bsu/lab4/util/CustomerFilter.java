package by.bsu.lab4.util;

import by.bsu.lab4.entity.Customer;

import java.math.BigDecimal;
import java.util.List;
import java.util.stream.Collectors;

public class CustomerFilter {

    public List<Customer> filterCustomersByCardNumber(List<Customer> customers, BigDecimal lowerBorder, BigDecimal upperBorder) {
        return customers.parallelStream()
                            .filter(customer -> customer.getCreditNumber().compareTo(lowerBorder) >= 0
                                        && customer.getCreditNumber().compareTo(upperBorder) <= 0)
                            .collect(Collectors.toList());
    }


}
