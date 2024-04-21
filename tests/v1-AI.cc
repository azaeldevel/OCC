
#include <vector>

#include "v1.hh"
#include "../1/occ.hh"
#include "../1/A/I/A.hh"
#include "../1/A/intel.hh"


void v1_AI_developing()
{
    //write a vector of pointers to occ::node
    std::vector<occ::node*> nodes;

    //add all general registers usando the node oc::A::Registers class, 8 and 16 btis
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::AL,"al",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::AH,"ah",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::AX,"ax",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::BL,"bl",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::BH,"bh",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::BX,"bx",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::CL,"cl",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::CH,"ch",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::CX,"cx",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::DL,"dl",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::DH,"dh",2));
    nodes.push_back(new occ::A::Register(occ::Statemants::reg,occ::Tokens::DX,"dx",2));

    //add a BX + SI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    //add a BX + DI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    //add a BP + SI
    nodes.push_back(new occ::A::Register(occ::Tokens::BP,"bp",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    //add a BX + DI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    //add a SI
    nodes.push_back(new occ::A::Register(occ::Tokens::SI,"si",2));
    //add a DI
    nodes.push_back(new occ::A::Register(occ::Tokens::DI,"di",2));
    //add memory
    nodes.push_back(new occ::A::Memory(occ::Integer(occ::Tokens::TINY,"100",3)));
    //add a BX

    //add a BX + SI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BX + DI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BP + SI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BP,"bp",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BX + DI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a SI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::SI,"si",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a DI + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::DI,"di",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BX + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BP + D8
    nodes.push_back(new occ::A::Register(occ::Tokens::BP,"bp",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::TINY,"100",3);
    //add a BX + SI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a BX + DI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a BP + SI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BP,"bp",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI,"si",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a BX + DI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI,"di",2);
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a SI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::SI,"si",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a DI + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::DI,"di",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a BX + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);
    //add a BP + D16
    nodes.push_back(new occ::A::Register(occ::Tokens::BP,"bp",2));
    nodes.back()->next = new occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5);

    occ::A::intel::Call call1(occ::Integer(occ::Statemants::number,occ::Tokens::SHORT,"10000",5),occ::A::intel::Call::within_direct);
    std::cout << "Code : " << call1.mcode[1] << "\n";
}








