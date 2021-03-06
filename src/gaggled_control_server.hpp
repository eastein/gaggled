#ifndef GAGGLED_CONTROL_SERVER_H_INCLUDED
#define GAGGLED_CONTROL_SERVER_H_INCLUDED

/* Auto-Generated by RPG. Don't edit this unless you really know what you're up to. No, really. */

#include <stdint.h>
#include <stdexcept>
#include <vector>
#include <string>
#include <zmq.hpp>
#include "rpgbase.hpp"

namespace gaggled_control_server {

    const uint8_t ST_AFFIRM = 0;
    const uint8_t ST_BADMSG = 1;
    const uint8_t ST_FAILED = 2;
    const uint32_t WIRE_VERSION = 5238;
    const uint32_t FNUM_GETSTATES = 1;
    const uint32_t FNUM_KILL = 2;
    const uint32_t FNUM_SHUTDOWN = 3;
    const uint32_t FNUM_START = 4;
    const uint32_t FNUM_STOP = 5;

    class BadMessage : public std::exception {
    public:
     // functions
     // members
    };

    class ProgramState {
    public:
     // functions
     // members
      uint8_t dependencies_satisfied;
      std::string down_type;
      uint8_t during_shutdown;
      uint8_t is_operator_shutdown;
      int64_t pid;
      std::string program;
      uint64_t state_sequence;
      uint8_t up;
      uint64_t uptime_ms;
    };

    template<typename implementation_child_type>
    class gaggled_control : public rpgbase::RPGService {
    public:
     // functions
      uint32_t decode_uint32_t (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        uint32_t ret;
        if ((buf_size >= ((*(buf_offset)) + 4))) {
          ret = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
        } else {
          throw BadMessage();
        }
        return ret;
      }
      void encode_uint32_t (uint8_t* outbuf, uint32_t* buf_offset, uint32_t obj) {
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj >> 24) & 255)));
        outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((obj >> 16) & 255)));
        outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((obj >> 8) & 255)));
        outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((obj >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 4);
      }
      int32_t decode_int32_t (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        int32_t ret;
        if ((buf_size >= ((*(buf_offset)) + 4))) {
          ret = ((((int32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((int32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((int32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((int32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
        } else {
          throw BadMessage();
        }
        return ret;
      }
      void encode_int32_t (uint8_t* outbuf, uint32_t* buf_offset, int32_t obj) {
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj >> 24) & 255)));
        outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((obj >> 16) & 255)));
        outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((obj >> 8) & 255)));
        outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((obj >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 4);
      }
      uint8_t decode_uint8_t (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        uint8_t ret;
        if ((buf_size >= ((*(buf_offset)) + 1))) {
          ret = (((uint8_t)(inbuf[((*(buf_offset)) + 0)])) << 0);
          (*(buf_offset)) = ((*(buf_offset)) + 1);
        } else {
          throw BadMessage();
        }
        return ret;
      }
      void encode_uint8_t (uint8_t* outbuf, uint32_t* buf_offset, uint8_t obj) {
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 1);
      }
      std::string decode_progname (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        char vchar_buf[256];
        uint32_t vchar_size;
        std::string ret;
        if ((buf_size >= ((*(buf_offset)) + 4))) {
          vchar_size = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
        } else {
          throw BadMessage();
        }
        if ((vchar_size > 255)) {
          throw BadMessage();
        }
        memcpy(vchar_buf, ((*(buf_offset)) + inbuf), vchar_size);
        vchar_buf[vchar_size] = 0;
        ret = std::string(vchar_buf);
        (*(buf_offset)) = ((*(buf_offset)) + vchar_size);
        return ret;
      }
      void encode_progname (uint8_t* outbuf, uint32_t* buf_offset, std::string obj) {
        uint32_t lencache=((&(obj)))->length();
        if ((lencache > 255)) {
          throw BadMessage();
        }
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((lencache >> 24) & 255)));
        outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((lencache >> 16) & 255)));
        outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((lencache >> 8) & 255)));
        outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((lencache >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 4);
        memcpy(((*(buf_offset)) + outbuf), ((&(obj)))->c_str(), lencache);
        (*(buf_offset)) = ((*(buf_offset)) + lencache);
      }
      std::string decode_username (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        char vchar_buf[256];
        uint32_t vchar_size;
        std::string ret;
        if ((buf_size >= ((*(buf_offset)) + 4))) {
          vchar_size = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
        } else {
          throw BadMessage();
        }
        if ((vchar_size > 255)) {
          throw BadMessage();
        }
        memcpy(vchar_buf, ((*(buf_offset)) + inbuf), vchar_size);
        vchar_buf[vchar_size] = 0;
        ret = std::string(vchar_buf);
        (*(buf_offset)) = ((*(buf_offset)) + vchar_size);
        return ret;
      }
      void encode_username (uint8_t* outbuf, uint32_t* buf_offset, std::string obj) {
        uint32_t lencache=((&(obj)))->length();
        if ((lencache > 255)) {
          throw BadMessage();
        }
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((lencache >> 24) & 255)));
        outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((lencache >> 16) & 255)));
        outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((lencache >> 8) & 255)));
        outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((lencache >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 4);
        memcpy(((*(buf_offset)) + outbuf), ((&(obj)))->c_str(), lencache);
        (*(buf_offset)) = ((*(buf_offset)) + lencache);
      }
      std::vector<ProgramState> decode_ProgramStateList (uint8_t* inbuf, uint32_t* buf_offset, uint32_t buf_size) {
        char vchar_buf[256];
        uint32_t vchar_size;
        std::vector<ProgramState> ret;
        uint32_t blsize;
        if ((buf_size >= ((*(buf_offset)) + 4))) {
          blsize = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
        } else {
          throw BadMessage();
        }
        if ((blsize > 1024)) {
          throw BadMessage();
        }
        for (uint32_t blidx=0; (blidx < blsize); blidx = (blidx + 1)) {
          ProgramState rd;
          if ((buf_size >= ((*(buf_offset)) + 1))) {
            rd.dependencies_satisfied = (((uint8_t)(inbuf[((*(buf_offset)) + 0)])) << 0);
            (*(buf_offset)) = ((*(buf_offset)) + 1);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 4))) {
            vchar_size = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
            (*(buf_offset)) = ((*(buf_offset)) + 4);
          } else {
            throw BadMessage();
          }
          if ((vchar_size > 4)) {
            throw BadMessage();
          }
          memcpy(vchar_buf, ((*(buf_offset)) + inbuf), vchar_size);
          vchar_buf[vchar_size] = 0;
          rd.down_type = std::string(vchar_buf);
          (*(buf_offset)) = ((*(buf_offset)) + vchar_size);
          if ((buf_size >= ((*(buf_offset)) + 1))) {
            rd.during_shutdown = (((uint8_t)(inbuf[((*(buf_offset)) + 0)])) << 0);
            (*(buf_offset)) = ((*(buf_offset)) + 1);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 1))) {
            rd.is_operator_shutdown = (((uint8_t)(inbuf[((*(buf_offset)) + 0)])) << 0);
            (*(buf_offset)) = ((*(buf_offset)) + 1);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 8))) {
            rd.pid = ((((int64_t)(inbuf[((*(buf_offset)) + 0)])) << 56) + ((((int64_t)(inbuf[((*(buf_offset)) + 1)])) << 48) + ((((int64_t)(inbuf[((*(buf_offset)) + 2)])) << 40) + ((((int64_t)(inbuf[((*(buf_offset)) + 3)])) << 32) + ((((int64_t)(inbuf[((*(buf_offset)) + 4)])) << 24) + ((((int64_t)(inbuf[((*(buf_offset)) + 5)])) << 16) + ((((int64_t)(inbuf[((*(buf_offset)) + 6)])) << 8) + (((int64_t)(inbuf[((*(buf_offset)) + 7)])) << 0))))))));
            (*(buf_offset)) = ((*(buf_offset)) + 8);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 4))) {
            vchar_size = ((((uint32_t)(inbuf[((*(buf_offset)) + 0)])) << 24) + ((((uint32_t)(inbuf[((*(buf_offset)) + 1)])) << 16) + ((((uint32_t)(inbuf[((*(buf_offset)) + 2)])) << 8) + (((uint32_t)(inbuf[((*(buf_offset)) + 3)])) << 0))));
            (*(buf_offset)) = ((*(buf_offset)) + 4);
          } else {
            throw BadMessage();
          }
          if ((vchar_size > 255)) {
            throw BadMessage();
          }
          memcpy(vchar_buf, ((*(buf_offset)) + inbuf), vchar_size);
          vchar_buf[vchar_size] = 0;
          rd.program = std::string(vchar_buf);
          (*(buf_offset)) = ((*(buf_offset)) + vchar_size);
          if ((buf_size >= ((*(buf_offset)) + 8))) {
            rd.state_sequence = ((((uint64_t)(inbuf[((*(buf_offset)) + 0)])) << 56) + ((((uint64_t)(inbuf[((*(buf_offset)) + 1)])) << 48) + ((((uint64_t)(inbuf[((*(buf_offset)) + 2)])) << 40) + ((((uint64_t)(inbuf[((*(buf_offset)) + 3)])) << 32) + ((((uint64_t)(inbuf[((*(buf_offset)) + 4)])) << 24) + ((((uint64_t)(inbuf[((*(buf_offset)) + 5)])) << 16) + ((((uint64_t)(inbuf[((*(buf_offset)) + 6)])) << 8) + (((uint64_t)(inbuf[((*(buf_offset)) + 7)])) << 0))))))));
            (*(buf_offset)) = ((*(buf_offset)) + 8);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 1))) {
            rd.up = (((uint8_t)(inbuf[((*(buf_offset)) + 0)])) << 0);
            (*(buf_offset)) = ((*(buf_offset)) + 1);
          } else {
            throw BadMessage();
          }
          if ((buf_size >= ((*(buf_offset)) + 8))) {
            rd.uptime_ms = ((((uint64_t)(inbuf[((*(buf_offset)) + 0)])) << 56) + ((((uint64_t)(inbuf[((*(buf_offset)) + 1)])) << 48) + ((((uint64_t)(inbuf[((*(buf_offset)) + 2)])) << 40) + ((((uint64_t)(inbuf[((*(buf_offset)) + 3)])) << 32) + ((((uint64_t)(inbuf[((*(buf_offset)) + 4)])) << 24) + ((((uint64_t)(inbuf[((*(buf_offset)) + 5)])) << 16) + ((((uint64_t)(inbuf[((*(buf_offset)) + 6)])) << 8) + (((uint64_t)(inbuf[((*(buf_offset)) + 7)])) << 0))))))));
            (*(buf_offset)) = ((*(buf_offset)) + 8);
          } else {
            throw BadMessage();
          }
          ((&(ret)))->push_back(rd);
        }
        return ret;
      }
      void encode_ProgramStateList (uint8_t* outbuf, uint32_t* buf_offset, std::vector<ProgramState> obj) {
        uint32_t listsize=((&(obj)))->size();
        if ((listsize > 1024)) {
          throw BadMessage();
        }
        outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((listsize >> 24) & 255)));
        outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((listsize >> 16) & 255)));
        outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((listsize >> 8) & 255)));
        outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((listsize >> 0) & 255)));
        (*(buf_offset)) = ((*(buf_offset)) + 4);
        for (uint32_t listoffset=0; (listoffset < listsize); listoffset = (listoffset + 1)) {
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].dependencies_satisfied >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 1);
          uint32_t lencache=((&(obj[listoffset].down_type)))->length();
          if ((lencache > 4)) {
            throw BadMessage();
          }
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((lencache >> 24) & 255)));
          outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((lencache >> 16) & 255)));
          outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((lencache >> 8) & 255)));
          outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((lencache >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
          memcpy(((*(buf_offset)) + outbuf), ((&(obj[listoffset].down_type)))->c_str(), lencache);
          (*(buf_offset)) = ((*(buf_offset)) + lencache);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].during_shutdown >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 1);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].is_operator_shutdown >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 1);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].pid >> 56) & 255)));
          outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((obj[listoffset].pid >> 48) & 255)));
          outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((obj[listoffset].pid >> 40) & 255)));
          outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((obj[listoffset].pid >> 32) & 255)));
          outbuf[((*(buf_offset)) + 4)] = ((uint8_t)(((obj[listoffset].pid >> 24) & 255)));
          outbuf[((*(buf_offset)) + 5)] = ((uint8_t)(((obj[listoffset].pid >> 16) & 255)));
          outbuf[((*(buf_offset)) + 6)] = ((uint8_t)(((obj[listoffset].pid >> 8) & 255)));
          outbuf[((*(buf_offset)) + 7)] = ((uint8_t)(((obj[listoffset].pid >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 8);
          uint32_t lencache_1=((&(obj[listoffset].program)))->length();
          if ((lencache_1 > 255)) {
            throw BadMessage();
          }
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((lencache_1 >> 24) & 255)));
          outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((lencache_1 >> 16) & 255)));
          outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((lencache_1 >> 8) & 255)));
          outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((lencache_1 >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 4);
          memcpy(((*(buf_offset)) + outbuf), ((&(obj[listoffset].program)))->c_str(), lencache_1);
          (*(buf_offset)) = ((*(buf_offset)) + lencache_1);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].state_sequence >> 56) & 255)));
          outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((obj[listoffset].state_sequence >> 48) & 255)));
          outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((obj[listoffset].state_sequence >> 40) & 255)));
          outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((obj[listoffset].state_sequence >> 32) & 255)));
          outbuf[((*(buf_offset)) + 4)] = ((uint8_t)(((obj[listoffset].state_sequence >> 24) & 255)));
          outbuf[((*(buf_offset)) + 5)] = ((uint8_t)(((obj[listoffset].state_sequence >> 16) & 255)));
          outbuf[((*(buf_offset)) + 6)] = ((uint8_t)(((obj[listoffset].state_sequence >> 8) & 255)));
          outbuf[((*(buf_offset)) + 7)] = ((uint8_t)(((obj[listoffset].state_sequence >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 8);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].up >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 1);
          outbuf[((*(buf_offset)) + 0)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 56) & 255)));
          outbuf[((*(buf_offset)) + 1)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 48) & 255)));
          outbuf[((*(buf_offset)) + 2)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 40) & 255)));
          outbuf[((*(buf_offset)) + 3)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 32) & 255)));
          outbuf[((*(buf_offset)) + 4)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 24) & 255)));
          outbuf[((*(buf_offset)) + 5)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 16) & 255)));
          outbuf[((*(buf_offset)) + 6)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 8) & 255)));
          outbuf[((*(buf_offset)) + 7)] = ((uint8_t)(((obj[listoffset].uptime_ms >> 0) & 255)));
          (*(buf_offset)) = ((*(buf_offset)) + 8);
        }
      }
      void recv_request (uint8_t* inbuf, uint32_t buf_size, uint8_t* outbuf, uint32_t* buf_offset) {
        uint32_t decode_offset=0;
        uint32_t wv=(this)->decode_uint32_t(inbuf, (&(decode_offset)), buf_size);
        if ((wv != WIRE_VERSION)) {
          throw BadMessage();
        }
        uint32_t fnumber=(this)->decode_uint32_t(inbuf, (&(decode_offset)), buf_size);
        (*(buf_offset)) = 0;
        (this)->encode_uint32_t(outbuf, buf_offset, WIRE_VERSION);
        switch (fnumber) {
          case FNUM_GETSTATES:
          {
            int32_t request_1;
            try {
              request_1 = (this)->decode_int32_t(inbuf, (&(decode_offset)), buf_size);
            } catch (...) {
              (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
              return;
            }
            try {
              std::vector<ProgramState> response=(static_cast<implementation_child_type*>(this))->handle_getstates(request_1);
              (this)->encode_uint8_t(outbuf, buf_offset, ST_AFFIRM);
              (this)->encode_ProgramStateList(outbuf, buf_offset, response);
            } catch (...) {
              (*(buf_offset)) = 4;
              (this)->encode_uint8_t(outbuf, buf_offset, ST_FAILED);
            }
            break;
          }
          case FNUM_KILL:
          {
            std::string request_2;
            try {
              request_2 = (this)->decode_progname(inbuf, (&(decode_offset)), buf_size);
            } catch (...) {
              (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
              return;
            }
            try {
              uint8_t response=(static_cast<implementation_child_type*>(this))->handle_kill(request_2);
              (this)->encode_uint8_t(outbuf, buf_offset, ST_AFFIRM);
              (this)->encode_uint8_t(outbuf, buf_offset, response);
            } catch (...) {
              (*(buf_offset)) = 4;
              (this)->encode_uint8_t(outbuf, buf_offset, ST_FAILED);
            }
            break;
          }
          case FNUM_SHUTDOWN:
          {
            std::string request_3;
            try {
              request_3 = (this)->decode_username(inbuf, (&(decode_offset)), buf_size);
            } catch (...) {
              (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
              return;
            }
            try {
              uint8_t response=(static_cast<implementation_child_type*>(this))->handle_shutdown(request_3);
              (this)->encode_uint8_t(outbuf, buf_offset, ST_AFFIRM);
              (this)->encode_uint8_t(outbuf, buf_offset, response);
            } catch (...) {
              (*(buf_offset)) = 4;
              (this)->encode_uint8_t(outbuf, buf_offset, ST_FAILED);
            }
            break;
          }
          case FNUM_START:
          {
            std::string request_4;
            try {
              request_4 = (this)->decode_progname(inbuf, (&(decode_offset)), buf_size);
            } catch (...) {
              (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
              return;
            }
            try {
              uint8_t response=(static_cast<implementation_child_type*>(this))->handle_start(request_4);
              (this)->encode_uint8_t(outbuf, buf_offset, ST_AFFIRM);
              (this)->encode_uint8_t(outbuf, buf_offset, response);
            } catch (...) {
              (*(buf_offset)) = 4;
              (this)->encode_uint8_t(outbuf, buf_offset, ST_FAILED);
            }
            break;
          }
          case FNUM_STOP:
          {
            std::string request_5;
            try {
              request_5 = (this)->decode_progname(inbuf, (&(decode_offset)), buf_size);
            } catch (...) {
              (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
              return;
            }
            try {
              uint8_t response=(static_cast<implementation_child_type*>(this))->handle_stop(request_5);
              (this)->encode_uint8_t(outbuf, buf_offset, ST_AFFIRM);
              (this)->encode_uint8_t(outbuf, buf_offset, response);
            } catch (...) {
              (*(buf_offset)) = 4;
              (this)->encode_uint8_t(outbuf, buf_offset, ST_FAILED);
            }
            break;
          }
          default:
          {
            (this)->encode_uint8_t(outbuf, buf_offset, ST_BADMSG);
            return;
          }
        }
      }
      std::vector<ProgramState> handle_getstates (int32_t req) {
        std::vector<ProgramState> ret;
        return ret;
      }
      uint8_t handle_kill (std::string req) {
        uint8_t ret;
        return ret;
      }
      uint8_t handle_shutdown (std::string req) {
        uint8_t ret;
        return ret;
      }
      uint8_t handle_start (std::string req) {
        uint8_t ret;
        return ret;
      }
      uint8_t handle_stop (std::string req) {
        uint8_t ret;
        return ret;
      }
      ~gaggled_control () {
        delete sock;
        if (ctx_created) {
          delete ctx;
        }
      }
      gaggled_control (const char* url, uint32_t threads=1, gaggled_control* compatriot=NULL) {
        if ((compatriot == NULL)) {
          ctx = new zmq::context_t(threads);
          ctx_created = true;
        } else {
          ctx = (*(compatriot)).ctx;
          ctx_created = false;
        }
        sock = new zmq::socket_t((*(ctx)), ZMQ_REP);
        (sock)->bind(url);
        pollitem.socket = (*(sock));
        pollitem.events = ZMQ_POLLIN;
      }
      void run_once (long timeout=0) {
        uint32_t busy=0;
        try {
          busy = zmq::poll((&(pollitem)), 1, timeout);
        } catch (zmq::error_t& ze) {
          return;
        }
        if ((busy > 0)) {
          (this)->run_once_bare();
        }
      }
      void run_once_bare () {
        zmq::message_t req;
        (sock)->recv((&(req)));
        bool bmsg=false;
        try {
          (this)->recv_request(((uint8_t*)(((&(req)))->data())), ((&(req)))->size(), ((uint8_t*)(msgbuf)), (&(msgbuf_s)));
        } catch (BadMessage& bme) {
          bmsg = true;
          (this)->encode_uint8_t(((uint8_t*)(msgbuf)), (&(msgbuf_s)), ST_BADMSG);
        }
        zmq::message_t resp(msgbuf_s);
        memcpy(((&(resp)))->data(), msgbuf, msgbuf_s);
        (sock)->send(resp);
        if (bmsg) {
          throw BadMessage();
        }
      }
     // members
      bool ctx_created;
      uint8_t msgbuf[302092];
      uint32_t msgbuf_s;
    };
}
#endif