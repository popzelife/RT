#include "rt.h"

void right_lmouse(t_rt *rt)
{
  {
    *rt->this_scene->this_cam = set_camera(
        v3_(rt->this_scene->this_cam->param.look_from.x - 1.,
            rt->this_scene->this_cam->param.look_from.y,
            rt->this_scene->this_cam->param.look_from.z),
        v3_(rt->this_scene->this_cam->param.look_at.x - 1.,
            rt->this_scene->this_cam->param.look_at.y,
            rt->this_scene->this_cam->param.look_at.z),
        rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
    udpate_view(rt);
    while (rt->iter->s == 0)
      render_low(rt);
    esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
    param_view_high(rt);
    rt->render = true;
  }
}

void left_lmouse(t_rt *rt)
{
  *rt->this_scene->this_cam = set_camera(
      v3_(rt->this_scene->this_cam->param.look_from.x + 1.,
          rt->this_scene->this_cam->param.look_from.y,
          rt->this_scene->this_cam->param.look_from.z),
      v3_(rt->this_scene->this_cam->param.look_at.x + 1.,
          rt->this_scene->this_cam->param.look_at.y,
          rt->this_scene->this_cam->param.look_at.z),
      rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
  udpate_view(rt);
  while (rt->iter->s == 0)
    render_low(rt);
  esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
  param_view_high(rt);
  rt->render = true;
}

void up_lmouse(t_rt *rt)
{
  *rt->this_scene->this_cam = set_camera(
      v3_(rt->this_scene->this_cam->param.look_from.x,
          rt->this_scene->this_cam->param.look_from.y + 1.,
          rt->this_scene->this_cam->param.look_from.z),
      v3_(rt->this_scene->this_cam->param.look_at.x,
          rt->this_scene->this_cam->param.look_at.y + 1.,
          rt->this_scene->this_cam->param.look_at.z),
      rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
  udpate_view(rt);
  while (rt->iter->s == 0)
    render_low(rt);
  esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
  param_view_high(rt);
  rt->render = true;
}

void down_lmouse(t_rt *rt)
{
  *rt->this_scene->this_cam = set_camera(
      v3_(rt->this_scene->this_cam->param.look_from.x,
          rt->this_scene->this_cam->param.look_from.y - 1.,
          rt->this_scene->this_cam->param.look_from.z),
      v3_(rt->this_scene->this_cam->param.look_at.x,
          rt->this_scene->this_cam->param.look_at.y - 1.,
          rt->this_scene->this_cam->param.look_at.z),
      rt->this_scene->this_cam->param.v_up, rt->this_scene->this_cam->param);
  udpate_view(rt);
  while (rt->iter->s == 0)
    render_low(rt);
  esdl_clear_surface(rt->s_process, NULL, 0x00000000, NULL);
  param_view_high(rt);
  rt->render = true;
}
