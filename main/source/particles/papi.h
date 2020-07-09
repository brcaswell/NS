// papi.h
//
// Copyright 1997-1998 by David K. McAllister
// http://www.cs.unc.edu/~davemc/Particle
//
// Include this file in all applications that use the Particle System API.

#ifndef _particle_api_h
#define _particle_api_h

#include <stdlib.h>

// This is the major and minor version number of this release of the API.
#define P_VERSION 120

// added <<< cgc >>>
#include "p_vector.h"
#include "general.h"
#include "particledefs.h"

// State setting calls

extern "C" {
	 void pColor(float red, float green, float blue, float alpha = 1.0f);

	 void pColorD(float alpha, PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pSize(float size_x, float size_y = 1.0f, float size_z = 1.0f);

	 void pSizeD(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pStartingAge(float age, float sigma = 1.0f);

	 void pTimeStep(float new_dt);

	 void pVelocity(float x, float y, float z);

	 void pVelocityD(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pVertexB(float x, float y, float z);

	 void pVertexBD(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pVertexBTracks(bool track_vertex = true);


	// Action List Calls

	 void pCallActionList(int action_list_num);

	 void pDeleteActionLists(int action_list_num, int action_list_count = 1);

	 void pEndActionList();

	 int pGenActionLists(int action_list_count = 1);

	 void pNewActionList(int action_list_num);


	// Particle Group Calls

	 ParticleGroup* pGetParticleGroupRef(int p_group_num);

	 void pCopyGroup(int p_src_group_num, int index = 0, int copy_count = P_MAXINT);

	 void pCurrentGroup(int p_group_num);

	 ParticleGroup* pGetCurrentGroup(void);

	 void pDeleteParticleGroups(int p_group_num, int p_group_count = 1);

	 void pDrawGroupl(int dlist, bool const_size = false,
		bool const_color = false, bool const_rotation = false);

	 void pDrawGroupp(int primitive, bool const_size = false,
		bool const_color = false);

	// Added <<< cgc >>>
	 void DrawGroupTriSplat(const pVector& view, const pVector& up, float size_scale = 1.0f, bool draw_tex = false, bool const_size = false, bool const_color = false);
	// end

	 int pGenParticleGroups(int p_group_count = 1, int max_particles = 0);

	 int pGetGroupCount();

	 int pGetParticles(int index, int count, float* position = NULL, float* color = NULL,
		float* vel = NULL, float* size = NULL, float* age = NULL);

	 int pSetMaxParticles(int max_count);


	// Actions

	 void pAvoid(float magnitude, float epsilon, float look_ahead,
		PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pBounce(float friction, float resilience, float cutoff,
		PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pCopyVertexB(bool copy_pos = true, bool copy_vel = false);

	 void pDamping(float damping_x, float damping_y, float damping_z,
		float vlow = 0.0f, float vhigh = P_MAXFLOAT);

	 void pExplosion(float center_x, float center_y, float center_z, float velocity,
		float magnitude, float stdev, float epsilon = P_EPS, float age = 0.0f);

	 void pFollow(float magnitude = 1.0f, float epsilon = P_EPS, float max_radius = P_MAXFLOAT);

	 void pGravitate(float magnitude = 1.0f, float epsilon = P_EPS, float max_radius = P_MAXFLOAT);

	 void pGravity(float dir_x, float dir_y, float dir_z);

	 void pJet(float center_x, float center_y, float center_z, float magnitude = 1.0f,
		float epsilon = P_EPS, float max_radius = P_MAXFLOAT);

	 void pKillOld(float age_limit, bool kill_less_than = false);

	 void pMatchVelocity(float magnitude = 1.0f, float epsilon = P_EPS,
		float max_radius = P_MAXFLOAT);

	 void pMove();

	 void pOrbitLine(float p_x, float p_y, float p_z,
		float axis_x, float axis_y, float axis_z, float magnitude = 1.0f,
		float epsilon = P_EPS, float max_radius = P_MAXFLOAT);

	 void pOrbitPoint(float center_x, float center_y, float center_z,
		float magnitude = 1.0f, float epsilon = P_EPS,
		float max_radius = P_MAXFLOAT);

	 void pRandomAccel(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pRandomDisplace(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pRandomVelocity(PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pRestore(float time);

	 void pShade(float color_x, float color_y, float color_z,
		float alpha, float scale);

	 void pSink(bool kill_inside, PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pSinkVelocity(bool kill_inside, PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pSource(float particle_rate, PDomainEnum dtype,
		float a0 = 0.0f, float a1 = 0.0f, float a2 = 0.0f,
		float a3 = 0.0f, float a4 = 0.0f, float a5 = 0.0f,
		float a6 = 0.0f, float a7 = 0.0f, float a8 = 0.0f);

	 void pSpeedLimit(float min_speed, float max_speed = P_MAXFLOAT);

	 void pTargetColor(float color_x, float color_y, float color_z,
		float alpha, float scale);

	 void pTargetSize(float size_x, float size_y, float size_z,
		float scale_x = 0.0f, float scale_y = 0.0f, float scale_z = 0.0f);

	 void pTargetVelocity(float vel_x, float vel_y, float vel_z, float scale);

	 void pVertex(float x, float y, float z);

	 void pVortex(float center_x, float center_y, float center_z,
		float axis_x, float axis_y, float axis_z,
		float magnitude = 1.0f, float epsilon = P_EPS,
		float max_radius = P_MAXFLOAT);
}
#endif
