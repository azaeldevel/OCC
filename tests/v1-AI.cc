
#include <vector>

#include "v1.hh"
#include "../1/occ.hh"
#include "../1/A/I/A.hh"
#include "../1/A/intel.hh"


void v1_AI_developing()
{
    std::vector<occ::node*> nodes;
    nodes.push_back(new occ::A::Register(occ::Tokens::AL));
    nodes.push_back(new occ::A::Register(occ::Tokens::AH));
    nodes.push_back(new occ::A::Register(occ::Tokens::AX));
    nodes.push_back(new occ::A::Register(occ::Tokens::BL));
    nodes.push_back(new occ::A::Register(occ::Tokens::BH));
    nodes.push_back(new occ::A::Register(occ::Tokens::BX));
    nodes.push_back(new occ::A::Register(occ::Tokens::CL));
    nodes.push_back(new occ::A::Register(occ::Tokens::CH));
    nodes.push_back(new occ::A::Register(occ::Tokens::CX));
    nodes.push_back(new occ::A::Register(occ::Tokens::DL));
    nodes.push_back(new occ::A::Register(occ::Tokens::DH));
    nodes.push_back(new occ::A::Register(occ::Tokens::DX));
    nodes.push_back(new occ::A::Register(occ::Tokens::BP));
    nodes.push_back(new occ::A::Register(occ::Tokens::SI));
    nodes.push_back(new occ::A::Register(occ::Tokens::DI));
    nodes.push_back(new occ::A::Register(occ::Tokens::SP));

    //add a BX + SI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI);
    //add a BX + DI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI);
    //add a BP + SI
    nodes.push_back(new occ::A::Register(occ::Tokens::BP));
    nodes.back()->next = new occ::A::Register(occ::Tokens::SI);
    //add a BX + DI
    nodes.push_back(new occ::A::Register(occ::Tokens::BX));
    nodes.back()->next = new occ::A::Register(occ::Tokens::DI);
    //add a SI
    nodes.push_back(new occ::A::Register(occ::Tokens::SI));
    //add a DI
    nodes.push_back(new occ::A::Register(occ::Tokens::DI));
    //add memory
    nodes.push_back(new occ::A::Memory(occ::Integer(occ::Tokens::TINY,"100",3)));
    //add a BX
    nodes.push_back(new occ::A::Register(occ::Tokens::BX,"bx",2));

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

    const occ::A::Register* reg;
    unsigned char mcode1;

    //AL
    reg = static_cast<const occ::A::Register*>(nodes[0]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 0)
    //AH
    reg = static_cast<const occ::A::Register*>(nodes[1]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 4)
    //AX
    reg = static_cast<const occ::A::Register*>(nodes[2]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 0)
    //BL
    reg = static_cast<const occ::A::Register*>(nodes[3]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 3)
    //BH
    reg = static_cast<const occ::A::Register*>(nodes[4]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 7)
    //BX
    reg = static_cast<const occ::A::Register*>(nodes[5]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 3)
    //CL
    reg = static_cast<const occ::A::Register*>(nodes[6]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 1)
    //CH
    reg = static_cast<const occ::A::Register*>(nodes[7]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 5)
    //CX
    reg = static_cast<const occ::A::Register*>(nodes[8]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 1)
    //DL
    reg = static_cast<const occ::A::Register*>(nodes[9]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 2)
    //DH
    reg = static_cast<const occ::A::Register*>(nodes[10]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 6)
    //DX
    reg = static_cast<const occ::A::Register*>(nodes[11]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 2)
    //BP
    reg = static_cast<const occ::A::Register*>(nodes[12]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 5)
    //SI
    reg = static_cast<const occ::A::Register*>(nodes[13]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 6)
    //DI
    reg = static_cast<const occ::A::Register*>(nodes[14]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 7)
    //SP
    reg = static_cast<const occ::A::Register*>(nodes[15]);
    mcode1 = 0;
    reg->mode(mcode1);
    CU_ASSERT(mcode1 == 3)
    mcode1 = 0;
    reg->rm(mcode1);
    CU_ASSERT(mcode1 == 4)

}








