# paxcc

_A pretty simple C++ Data Passenger_; PAX is an airborne code.

## Introduction

The PAX class is a C++ written _object tree_. It is the enabler for parsing
any kind of -- hierarchically -- structured data to PAX; e.g. using XMLs SAX interfacing.

## ChangeLOG

- 250202 Adding _Visual Studio Code_ debugging configuration using g++ and gdb.
         Adding _PaxMap_ a sequence ordered hash map as template implementation.
         Adding _Pax_ keeping _Children_ and _Attributes_ that have _Pax_ types
         again, representing a complex _Composite Pattern_ from the _Software
         Design Patterns_ philosophy. Adding recursive generation of XML for
         Pax build object trees.
- 250201 Created the paxcc project and added make.
