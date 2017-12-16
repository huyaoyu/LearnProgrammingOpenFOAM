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

Description
    Template for use with code generation of a OutputFilter 
    functionObject.

SourceFiles
    functionObject.C

\*---------------------------------------------------------------------------*/

#ifndef myFunctionObject_H
#define myFunctionObject_H

#include "functionObject.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         A templated functionObject
\*---------------------------------------------------------------------------*/

class myFunctionObject
    :
        public functionObject
{
    // Private data

        //- Time
        const Time& time_; 

public:

    //- Runtime type information
    TypeName("myFunctionObject");

    // Constructors

        //- Construct for given objectRegistry and dictionary.
        //  Allow the possibility to load fields from files
        myFunctionObject
        (
            const word& name,
            const Time& time,
            const dictionary& dict
        );

    //- Destructor
     ~myFunctionObject();


    // Member Functions

        //- Access time
        const Time& getTime() const
        {
            return time_; 
        }

        //- Read the system calls
         bool read(const dictionary&);

        //- Execute the "executeCalls" at each time-step
         bool execute(const bool forceWrite=false);

        //- Called at the start of the time-loop
         bool start();

        //- Execute the "endCalls" at the final time-loop
         bool end();

        //- Called when time was set at the end of the Time::operator++
         bool timeSet();

        //- Update for changes of mesh
         void updateMesh(const mapPolyMesh&);

        //- Update for changes of mesh
         void movePoints(const polyMesh&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
