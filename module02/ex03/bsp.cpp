#include "Point.hpp"
#include <iostream>

typedef struct s_vec
{
    Fixed x;
    Fixed y;
} t_vec2;

static t_vec2 vec2_minus(Point const v1, Point const v2)
{
    t_vec2 result;

    result.x = v1.getX() - v2.getX();
    result.y = v1.getY() - v2.getY();
    return (result);
}

static Fixed CrossProductDir(t_vec2 const v1, t_vec2 const v2)
{
    return (v1.x * v2.y - v1.y * v2.x);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    t_vec2 ab, bc, ca, ap, bp, cp;
    Fixed dir1, dir2, dir3;

    ab = vec2_minus(b, a);
    bc = vec2_minus(c, b);
    ca = vec2_minus(a, c);
    ap = vec2_minus(point, a);
    bp = vec2_minus(point, b);
    cp = vec2_minus(point, c);
    dir1 = CrossProductDir(ab, ap);
    dir2 = CrossProductDir(bc, bp);
    dir3 = CrossProductDir(ca, cp);

    // 컴파일러가 생성자를 찾아서 생성 후 비교
    return (((dir1 > 0 && dir2 > 0 && dir3 > 0) ||
             (dir1 < 0 && dir2 < 0 && dir3 < 0)));
}