/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:43:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/26 18:34:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    {
        std::cout << "TEST 1" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longeset span : " << sp.longestSpan() << std::endl;
    }

    {
        std::cout << std::endl << "TEST 2" << std::endl;
        Span sp = Span(3);
        try
        {
            sp.addNumber(1);
            sp.addNumber(1);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << std::endl << "TEST 3" << std::endl;
        Span sp = Span(3);
        try
        {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << std::endl << "TEST 4" << std::endl;
        std::vector<int> vec;
        vec.push_back(20);
        vec.push_back(100);
        vec.push_back(80);
        vec.push_back(5);

        Span sp = Span(5);
        try
        {
            sp.addNumber(1);
            sp.addNumbers(vec.begin(), vec.end());
            std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
            std::cout << "longeset span : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << std::endl << "TEST 5" << std::endl;
        std::vector<int> vec;
        vec.push_back(20);
        vec.push_back(100);
        vec.push_back(80);
        vec.push_back(5);
        vec.push_back(10);

        Span sp = Span(5);
        try
        {
            sp.addNumber(1);
            sp.addNumbers(vec.begin(), vec.end());
            std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
            std::cout << "longeset span : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << std::endl << "TEST 6" << std::endl;
        std::vector<int> vec;
        vec.push_back(20);
        vec.push_back(80);
        vec.push_back(100);
        vec.push_back(1);

        Span sp = Span(5);
        try
        {
            sp.addNumber(1);
            sp.addNumbers(vec.begin(), vec.end());
            std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
            std::cout << "longeset span : " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}