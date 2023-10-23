/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:35:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/10/23 14:29:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = NULL;
    }
    for (int i = 0; i < kMaxMateria; i++)
    {
        materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &ms)
{
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    // for (int i = 0; i < kMaxMateria; i++)
    // {
    //     materias[i] = NULL;
    // }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < kMateria; i++)
    {
        if (materias[i])
        {
            delete materias[i];
        }
    }
    for (int i = 0; i < kMaxMateria; i++)
    {
        if (createdMaterias[i])
        {
            delete createdMaterias[i];
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ms)
{
    for (int i = 0; i < kMateria; i++)
    {
        materias[i] = ms.materias[i];
    }
    // for (int i = 0; i < kMaxMateria; i++)
    // {
    //     materias[i] = NULL;
    // }
    return *this;
}

void MateriaSource::equip(AMateria *m)
{
    for (int i = 0; i < kMaxMateria; i++)
    {
        if (!createdMaterias[i])
        {
            createdMaterias[i] = m;
            return;
        }
    }
    std::cout << "error: and your player cannot unequip return";
}

void MateriaSource::unequip(AMateria *m)
{
    for (int i = 0; i < kMaxMateria; i++)
    {
        if (createdMaterias[i] == m)
        {
            createdMaterias[i] = NULL;
            return;
        }
    }
    std::cout << "error: Materia not found.\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < kMateria; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
    std::cout << "error: MateriaSource is full.\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < kMateria; i++)
    {
        if (materias[i]->getType() == type)
        {
            AMateria *newMateria = materias[i]->clone();
            newMateria->setSource(this);
            // should be done cause materias[i]'s source are null (in main)
            for (int j = 0; j < kMaxMateria; j++)
            {
                if (!createdMaterias[j])
                {
                    createdMaterias[j] = newMateria;
                    return newMateria;
                }
            }
            std::cout << "error: MateriaSource cannot create materia more "
                         "than 1024.\n";
            return NULL;
        }
    }
    return NULL;
}