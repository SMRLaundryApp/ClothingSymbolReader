/******************************************************************************
 *	Copyright (C) 2020	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	GPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* include guard ********************************************************
 ******************************************************************************/
#pragma once	/* dbg.h */


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include <stdbool.h>

#define ALX_NO_PREFIX
#include <libalx/base/errno/perror.h>
#include <libalx/base/stdio/seekc.h>
#include <libalx/extra/cv/highgui/window.h>


/******************************************************************************
 ******* macro ****************************************************************
 ******************************************************************************/
#define DBG			0
#define DBG_SHOW_WAIT		0
#define DBG_SHOWTIME(dbg)	(					\
{									\
	int	tm_;							\
									\
	switch (dbg) {							\
	case 0:								\
		tm_	= 5000;						\
		break;							\
	case 1:								\
		tm_	= 1000;						\
		break;							\
	case 2:								\
		tm_	= 300;						\
		break;							\
	case 3:								\
		tm_	= 100;						\
		break;							\
	case 4:								\
		tm_	= 30;						\
		break;							\
	}								\
									\
	if (DBG_SHOW_WAIT)						\
		tm_	= -1;						\
									\
	tm_;								\
}									\
)

#if defined(DBG)
#define dbg_show(dbg, img)		do				\
{									\
									\
	if (dbg <= DBG) {						\
		perrorx(NULL);						\
		alx_cv_imshow(img, "dbg", DBG_SHOWTIME(dbg));		\
	}								\
} while (0);

#define dbg_printf(dbg, fmt, ...)	do				\
{									\
									\
	if (dbg <= DBG) {						\
		printf(fmt, ##__VA_ARGS__);				\
	}								\
} while (0);

#define dbg_update_win()		do				\
{									\
									\
	if (DBG) {							\
		alx_cv_destroy_all_windows();				\
		alx_cv_named_window("dbg", ALX_CV_WINDOW_NORMAL);	\
	}								\
} while (0);
#else
#define dbg_show(dbg, img)	do {} while (0);
#define dbg_update_win()	do {} while (0);
#endif	/* defined(DBG) */

#define MAX_SYMBOLS	(6)


#define TEMPLATES_DIR	"templates/"
#define T_BASE_DIR	TEMPLATES_DIR "base/"
#define T_INNER_DIR	TEMPLATES_DIR "inner/"
#define TEMPLATES_EXT	"png"


/******************************************************************************
 ******* enum *****************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* struct / union *******************************************************
 ******************************************************************************/


/******************************************************************************
 ******* prototypes ***********************************************************
 ******************************************************************************/


/******************************************************************************
 ******* inline ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
