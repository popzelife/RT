#include "rt.h"

t_viewparam new_viewparam(t_scene *scene)
{
  t_viewparam p;

  p.scene.sizeof_cam = 1;
  p.scene.cam = (t_cam *)malloc(p.scene.sizeof_cam * sizeof(t_cam));
  p.scene.cam[0] = set_camera(v3_(-.6, .0, -.6), v3_(0., 0., 0.),
                              v3_(0., -1., 0.), camparam(60., 1., 0., .5));
  p.scene.this_cam = &p.scene.cam[0];
  p.scene.sizeof_obj = 2;
  p.scene.obj = (t_obj *)malloc(p.scene.sizeof_obj * sizeof(t_obj));
  p.scene.obj[0] = copy_object(scene->this_obj);
  p.scene.obj[1] = new_object((void *)new_sphere(v3_(0., 1.5, 0.), .5),
                              OBJ_SPHERE, new_material(v3_(1., 1., 1.), 0., NULL), MAT_DIFF_LIGHT);
  p.scene.this_obj = scene->this_obj;
  p.scene.sizeof_skb = 1;
  p.scene.skybox = (t_skybox *)malloc(p.scene.sizeof_skb * sizeof(t_skybox));
  p.scene.skybox[0] = new_skybox(v3_(.4, .4, .4), v3_(.9, .9, .9),
                                 SKYBX_GRADIENT);
  p.scene.this_skb = &p.scene.skybox[0];
  return (p);
}

void set_viewparam(t_viewparam *p, t_rt *rt, int x, int y)
{
  t_hit param;
  t_ray ray;
  double u;
  double v;
  double t[2];

  t[0] = .001;
  t[1] = FLT_MAX;
  u = (double)x / (double)rt->r_view->w;
  v = (double)y / (double)rt->r_view->h;
  ray = ray_from_cam(rt->this_scene->this_cam, u, v);
  param.pos = v3_(0., 0., 0.);
  param.normal = v3_(0., 0., 0.);
  if (hit_list(rt->this_scene, ray, t, &param))
  {
    rt->this_scene->this_obj = &rt->this_scene->obj[param.i_lst];
    free(p->scene.obj[0].p_obj);
    free(p->scene.obj[0].p_mat);
    p->scene.obj[0] = copy_object(&rt->this_scene->obj[param.i_lst]);
    p->scene.this_obj = &rt->this_scene->obj[param.i_lst];
  }
}

t_camparam camparam(double vfov, double aspect, double aperture,
                    double focus)
{
  t_camparam p;

  p.vfov = vfov;
  p.aspect = aspect;
  p.aperture = aperture;
  p.focus = focus;
  return (p);
}

void reset_view(t_rt *rt)
{
  rt->this_scene->this_obj = rt->this_scene->this_obj;
  free(rt->panel.viewparam.scene.obj[0].p_obj);
  free(rt->panel.viewparam.scene.obj[0].p_mat);
  rt->panel.viewparam.scene.obj[0] = copy_object(rt->this_scene->this_obj);
  rt->panel.viewparam.scene.this_obj = rt->this_scene->this_obj;
  update_menu(rt);
}
