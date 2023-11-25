/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:23:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/11/25 15:31:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

int main()
{
    {
        Base *bptr = Identifier::generate();
        Identifier::identify(bptr);
        Identifier::identify(*bptr);
    }
    return 0;
}