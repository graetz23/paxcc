# paxcc

_A pretty simple C++ Data Passenger_; PAX is an airborne code.

## Introduction

The PAX class is a C++ written _object tree_. It is the enabler for parsing
any kind of - hierarchically - structured data to PAX; e.g. using XMLs SAX
interfacing and building a multi-dimensional object tree of _Paxs_.

A _Pax_ objects can take:
    - a _tag_ name as std::string,
    - a _value_ as std::string,
    - any _attributes_ as pairs of _tag_ and _value,
    - any _Pax_ object as _children_ of the current,
    - may generate themselves to _extensible markup language (XML)_.

Therefore, the _Pax_ objects allow for building multi-dimensional object trees
that are infinitively deep. Any _Pax_ can reproduce itself recusively to XML,
JSON (to follow), and protobuf (to follow).

## HowTo

How to use _Pax_, build object tree, and what can go wrong.

### Creating, Setting, Changing, and Deleting _Pax_ trees

Creating _Pax_ objects:

```C++

    Pax* pax1 = new Pax("Bob", "Dylon");

    Pax *pax2 = new Pax();
    pax2->Tag("Bob");
    pax2->Val("Dylon");

    Pax* pax3 = new Pax("Bob");

```

Adding _Attributes_ to _Pax_ objects:

```C++
    Pax* pax1 = new Pax("Bob", "Dylon");
    pax1->Attrib()->add("plays", "guitar");
    pax1->Attrib()->add("sings", "songs");
```

Adding _Children_ to _Pax_ objects:

```C++
    Pax* pax1 = new Pax("Bob", "Dylon");
    Pax* pax2 = new Pax("Dolly", "Parton");
    Pax* pax3 = new Pax("Johnny", "Cash");

    pax1->Child()->add(pax2); // pax2 as child of pax1
    pax2->Child()->add(pax3); // pax3 as child of pax2
```

Deleting _Pax_ objects:

```C++
    Pax* root = new Pax("Bob", "Dylon");
    Pax* pax2 = new Pax("Dolly", "Parton");
    Pax* pax3 = new Pax("Johnny", "Cash");

    root->Child()->add(pax2); // pax2 as child of pax1
    pax2->Child()->add(pax3); // pax3 as child of pax2

    delete root; // runs recursively ..
```

Generating XML from _Pax_ and writing to _std::out_:

```C++
    Pax* pax1 = new Pax("Bob", "Dylon");
    pax1->Attrib()->add("plays", "guitar");
    pax1->Attrib()->add("sings", "songs");

    Pax* pax2 = new Pax("Dolly", "Parton");
    pax2->Attrib()->add("sings", "songs");
    pax2->Attrib()->add("plays", "country guitar");
    
    
    Pax* pax3 = new Pax("Johnny", "Cash");
    pax3->Attrib()->add("plays", "guitar");
    pax3->Attrib()->add("sings", "country songs");

    Pax* pax4 = new Pax("John", "Denver");
    pax4->Attrib()->add("sings", "country songs");
    pax4->Attrib()->add("plays", "country guitar");

    pax1->Child()->add(pax2); // pax2 as child of pax1
    pax2->Child()->add(pax3); // pax3 as child of pax2
    pax2->Child()->add(pax4); // pax3 as child of pax2

    std::string xml = pax1->XML();
    std::cout << xml << std::endl << std::flush;

    delete pax1; // runs recursively
```

The XML of above example looks like:

```XML
    <Bob plays="guitar" sings="songs">
        <Dolly sings="songs" plays="country guitar">
            <Johnny plays="guitar" sings="country songs">Cash</Johnny>
            <John sings="country songs" plays="country guitar">Denver</John>
        </Dolly>
    </Bob>
```

Retrieving _Pax_ from above example:

```C++
  // assume we have build above Pax object tree ..

  Pax* pax2_ = pax1->Child("Dolly");

  Pax* pax3_ = pax2->Child("Johnny"); // from pax2
  
  Pax* pax4_ = pax1->Child("Dolly")->Child("John"); // chained

```

Retrieving _Tag_ and _Value_:

```C++
  Pax* pax = pax1->Child("Dolly")->Child("John"); // chained
  std::string tag = pax->Tag();
  std::string val = pax->Val();

```

Retrieving _Attributes_ _Tag_ and _Value_:

```C++
  Pax* pax = pax1->Child("Dolly")->Child("John"); // chained
  std::string attribTag = pax->Attrib("sings")->Tag();
  std::string attribVal = pax->Attrib("sings")->Val();
```

### What can go wrong

#### Deleting treed _Pax_ outside the tree

The problem in pointered C++ is, that there is no garbage collector that
collects any memory address and holds a pointer for automatic deletion on it.
Therefore, within _Pax_ it is possible to delete objects not recursively by
the tree, but outside the tree. This leads to a memory gap, where the object
tree still holds the pointer but the object is deleted. The recursive calling
methods stumbles over it an crashes off course. Here is an easy example to
produce this error:

```C++
    Pax* root = new Pax("Bob", "Dylon");
    Pax* pax2 = new Pax("Dolly", "Parton");
    Pax* pax3 = new Pax("Johnny", "Cash");

    root->Child()->add(pax2); // pax2 as child of pax1
    pax2->Child()->add(pax3); // pax3 as child of pax2

    delete pax2; // the error one can make ..

    delete root; // runs recursively .. and crashes!
```

The reason is simple. The Higher _Pax_ holds in his child list still the pointer
to the address of the delete _pax2_. As soon as this list of child is iterated,
the crash is there. There is no known chance to overcome this issue in ANSI C++.

#### Changing _Tags_ and _Values_ of a treed _Pax_

If an _already treed Pax_ is retrieved and the _Tag_ or the _Value_ is changed,
the object tree is not updated. Therefore, the object tree holds in the matching
_Pax_ of higher hierarchy still the old _Tag_ to the address of the changed _Pax_.
The following example details this issue:

```C++
    Pax* root = new Pax("Bob", "Dylon");
    Pax* pax2 = new Pax("Dolly", "Parton");
    Pax* pax3 = new Pax("Johnny", "Cash");

    root->Child()->add(pax2); // pax2 as child of pax1
    pax2->Child()->add(pax3); // pax3 as child of pax2

    Pax* pax = root->Child("Dolly")->Child("Johnny");

    pax->Tag("John"); // updating Tag
    pax->Val("Denver"); // updating Value

    Pax* pax2_ = root->Child("Dolly"); // remeber Dolly knows Johnny

    Pax* pax3_ = pax2->Child("Johnny"); // exists
    std::string tag = pax3_.Tag(); // John was stored
    std::string val = pax3_.Val(); // Denver was stored

    // and 

    Pax* pax3__ = pax2->Child("John"); // null pointer

    delete root; // runs recursively ..
```

This leads to the fact, that if one wants to change data on treed _Pax_,
he has to also deal with the object tree. Therefore, retrieving the object
above, deleting the _Pax_ from object tree, changing it, and adding it again.

## Building the PAXCC

For building PAXCC two build tools are available.

### Static Make

For the static Makefile using g++:
```bash
make
```
For cleaning up:
```bash
make clean
```

## Cmake Build Tooling

For modern CMake version install _CMake_ and _ninja_.
For generating ninja build files and building via ninja:
```bash
./build.sh
```
For cleaning up, remove the generated _build_ directory:
```bash
rm -rf build/
```

## ChangeLog

- 250202 Adding _Visual Studio Code_ debugging configuration using g++ and gdb.
         Adding _PaxMap_ a sequence ordered hash map as template implementation.
         Adding _Pax_ keeping _Children_ and _Attributes_ that have _Pax_ types
         again, representing a complex _Composite Pattern_ from the _Software
         Design Patterns_ philosophy. Adding recursive generation of XML for
         Pax build object trees. Adding possibility to add any Pax of same tag
         name.
- 250201 Created the paxcc project and added make.
