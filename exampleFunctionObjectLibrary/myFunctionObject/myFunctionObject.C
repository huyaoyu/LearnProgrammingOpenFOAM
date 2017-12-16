/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2013 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "myFunctionObject.H"
#include "addToRunTimeSelectionTable.H"
#include "error.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(myFunctionObject, 0);
addToRunTimeSelectionTable(functionObject, myFunctionObject, dictionary); 


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

myFunctionObject::myFunctionObject
(
    const word& name,
    const Time& time,
    const dictionary& dict
)
:
    functionObject(name),
    time_(time)
{
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

myFunctionObject::~myFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool myFunctionObject::read(const dictionary& dict)
{
    notImplemented("myFunctionObject::read(const dictionary&)"); 
    return execute(false); 
}


bool myFunctionObject::execute(const bool forceWrite)
{
    notImplemented("myFunctionObject::execute(const bool)"); 
    return true;
}

bool myFunctionObject::start()
{
    notImplemented("myFunctionObject::start()"); 
    return true;
}


bool myFunctionObject::end()
{
    notImplemented("myFunctionObject::end()"); 
    return execute(false);
}


bool myFunctionObject::timeSet()
{
    notImplemented("myFunctionObject::timeSet()"); 
    return true;
}

void myFunctionObject::updateMesh(const mapPolyMesh& map)
{
    notImplemented("myFunctionObject::updateMesh(const mapPolyMesh&)"); 
}

void myFunctionObject::movePoints(const polyMesh& mesh)
{
    notImplemented("myFunctionObject::movePoints(const polyMesh&)"); 
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam


// ************************************************************************* //
