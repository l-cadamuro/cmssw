// Class for AMC13 Header

#ifndef __l1t_emtf_AMC13Header_h__
#define __l1t_emtf_AMC13Header_h__

#include <vector>
#include <boost/cstdint.hpp>

namespace l1t {
  namespace emtf {
    class AMC13Header {
      
    public:
      explicit AMC13Header(uint64_t dataword); 
      
    // Empty constructor
    AMC13Header() :
      orn(-99), lv1_id(-99), bx_id(-99), source_id(-99), evt_ty(-99), fov(-99), ufov(-99), res(-99), namc(-99), h(-99), x(-99), dataword(-99)
	{};
      
    // Fill constructor
    AMC13Header(int int_orn, int int_lv1_id, int int_bx_id, int int_source_id, int int_evt_ty, int int_fov, int int_ufov, int int_res, int int_namc, int int_h, int int_x) :
      orn(int_orn), lv1_id(int_lv1_id), bx_id(int_bx_id), source_id(int_source_id), evt_ty(int_evt_ty), fov(int_fov), ufov(int_ufov), res(int_res), namc(int_namc), h(int_h), x(int_x), dataword(-99)
	{};
      
      virtual ~AMC13Header() {};
      
      void set_orn(int bits)          {  orn = bits; };
      void set_lv1_id(int bits)       {  lv1_id = bits; };
      void set_bx_id(int bits)        {  bx_id = bits; };
      void set_source_id(int bits)    {  source_id = bits; };
      void set_evt_ty(int bits)       {  evt_ty = bits; };
      void set_fov(int bits)          {  fov = bits; };
      void set_ufov(int bits)         {  ufov = bits; };
      void set_res(int bits)          {  res = bits; };
      void set_namc(int bits)         {  namc = bits; };
      void set_h(int bits)            {  h = bits; };
      void set_x(int bits)            {  x = bits; };
      void set_dataword(uint64_t bits)  { dataword = bits; };
      
      const int ORN()         const { return  orn ; };
      const int LV1_id()      const { return  lv1_id ; };
      const int BX_id()       const { return  bx_id ; };
      const int Source_id()   const { return  source_id ; };
      const int Evt_ty()      const { return  evt_ty ; };
      const int FOV()         const { return  fov ; };
      const int UFOV()        const { return  ufov ; };
      const int Res()         const { return  res ; };
      const int Namc()        const { return  namc ; };
      const int H()           const { return  h ; };
      const int X()           const { return  x ; };
      const uint64_t Dataword()     const { return dataword; };
      
    private:
      int  orn;
      int  lv1_id;
      int  bx_id;
      int  source_id;
      int  evt_ty;
      int  fov;
      int  ufov;
      int  res;
      int  namc;
      int  h;
      int  x;
      uint64_t dataword; 
      
    }; // End class AMC13Header
  } // End namespace emtf
} // End namespace l1t

#endif /* define __l1t_emtf_AMC13Header_h__ */
