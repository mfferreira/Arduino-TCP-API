#ifndef COMMON_H_
#define COMMON_H_

#define SYNC_CHAR '~'

typedef enum {
  NULL_MESSAGE    = '0',
  SERIAL_BEGIN    = '1',
  SERIAL_END      = '2',
  SERIAL_WRITE    = '3',
  SERIAL_WRITELN  = '4'
} APIEnum;

#endif  // COMMON_H_
