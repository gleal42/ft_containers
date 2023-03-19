
#ifndef __COMPARE_H__
#define __COMPARE_H__

struct Compare {
    bool operator()(const int lhs, const int rhs) const;
};

#endif // __COMPARE_H__
