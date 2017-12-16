/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by authors 
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    testSmartPointers

Description
    Test application for smart pointers.

Authors:
    Tomislav Maric tomislav@sourceflux.de
    Jens Hoepken jens@sourceflux.de
    Kyle Mooney kyle.g.mooney@gmail.com

Contributors:

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"

#include <string>

template<typename Type>
class infoField 
: 
    public Field<Type>
{
    public: 

        infoField(const char* n = "Default")
            : 
                Field<Type>(),
                name(n)
        {
            Info << name << ": empty constructor" << endl;
        }

        infoField(const infoField& other)
            : 
                Field<Type>(other),
                name(other.name)
        {
            Info << name << ": copy constructor" << endl;
        }

        infoField (int size, Type value, const char* n)
            : 
                Field<Type>(size, value),
                name(n)
        {
            Info << name << ": size, value constructor" << endl;
        }

        ~infoField()
        {
            Info << name << ": destructor" << endl;
        }

        void operator=(const infoField& other)
        {
            if (this != &other)
            {
                Field<Type>::operator=(other);  
                Info << name << ": assignment operator" << endl;
            }
        }

    protected:

        std::string name;
};

// The argument t doesn't require a copy operation since it is
// a reference to a const Type object.
template<typename Type>
Type valueReturn(Type const & t)
{
    Info << "Inside valueReturn." << endl;

    // One copy construction for the temporary.
    Type temp = t; 

    // One explicit assignment.
    temp = t;

    // ... operations (e.g. interpolation) on the temporary variable. 
    
    return temp; 
}

// Shorten the type name.  
typedef infoField<scalar> infoScalarField;


// Empty class for testing tmp. 
class testClass {}; 

// Empty class inherits refCount for working tmp.
class testClassCounted : public refCount {}; 

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// Main program:

int main(int argc, char *argv[])
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info << "Value construction : "; 
    infoScalarField valueConstructed(1e07, 5, "if00");  

    Info << "Empty construction : "; 
    infoScalarField assignedTo("assignedTo"); 

    Info << "Function call" << endl; 
    assignedTo = valueReturn(valueConstructed); 
    Info << "Function exit" << endl; 
    
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    // Construct the infoField pointer 
    autoPtr<infoScalarField> ifPtr (new infoScalarField(1e06, 0, "if01"));  

    // Output the pointer data by accessing the reference -  
    // using the operator T const & autoPtr<T>::operator()
    Info << ifPtr() << endl;

    // Create a copy of the ifPtr and transfer the object ownership
    // to ifPtrCopy. 
    autoPtr<infoScalarField> ifPtrCopy (ifPtr);  

    Info << ifPtrCopy() << endl;

    // Segmentation fault - accessing a deleted pointer. 
    // Info << ifPtr() << endl; 

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


    // Fails, testClass does not adhere to the refCount interface.
    //tmp<testClass> t1(new testClass()); 
    
    // Use infoScalarField to see that only a single object is constructed
    // and destroyed, and how the references are incremented and decremented.
    
    // Showing reference counts.
    tmp<infoScalarField> t1(new infoScalarField(1e06, 0, "if02")); 
    Info << "reference count = " << t1->count() << endl; 
    {
        tmp<infoScalarField> t2 (t1); 
        Info << "reference count = " << t1->count() << endl; 
        {
            // This will cause an exception since tmp doesn't allow
            // reusing an object for more than two times.
            // tmp<infoScalarField> t3(t2); 
            // Info << "reference count = " << t1->count() << endl; 
        } // t3 destructor called
        
        Info << "reference count = " << t1->count() << endl; 
    } // t2 destructor called
    Info << "reference count = " << t1->count() << endl; 

    return 0;
} 


// ************************************************************************* //
