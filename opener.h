#ifndef OPENER_H
#define OPENER_H

//
// opener.h
//
// MIT licensed.
// Copyright (c) Abraham Hernandez <abraham@abranhe.com>
//

#ifdef __cplusplus
extern "C" {
#endif

int opener(const char *url);

const char * operating_system(void);

#ifdef __cplusplus
}
#endif

#endif // OPENER_H