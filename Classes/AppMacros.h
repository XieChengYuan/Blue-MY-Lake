#ifndef _APPMACROS_H_
#define _APPMACROS_H_

#include "GlobalPath.h"
#include "cocos2d.h"
//update:2014-9-29 13:23:33


//layer����������scene������ĸ��layer����LAYER
//layer��100+
#define HELLOWORLDLAYER 100

//HelloWorld�Ķ���
#define MAPLAYER 101
#define CONTROLPANELLAYER 102

//MapLayer�Ķ���
#define MAP 590
#define HERO 510

//Map�Ķ���
#define TURNINGMAN_START 36 
#define TURNINGMAN_END 45
#define STANDINGMAN_START 46
#define STANDINGMAN_END 55

//ControlPanel�Ķ���
#define RWINDOW 521
#define BIGWINDOW 522
#define DIAWINDOW 523
#define DIRBUTTON 1
#define BUTTONA 10
#define TOUCHSCREEN 100

//Combat�Ķ���
#define BACKGROUND 100 



//Entity bind��sprite������IMGSP
#define IMGSP 500
#define DIABOXSP 501
#define LABELSP 502
#define CONTENTSP 503

//��ͼ�����������ͼ������_MLYR
#define EVENT_MLYR "event"
#define BUILDING2_MLYR "building2"
#define BUILDING_MLYR "building"
#define WALL_MLYR "wall"
#define FLOOR2_MLYR "floor2"
#define FLOOR_MLYR "floor"
#define WATER_MLYR "water"

//��Ϸ��¼������������������������_RCD
#define FIRSTSAVE_RCD "FisrtSave"
#define POSITIONX_RCD "PositionX"
#define POSITIONY_RCD "PositionY"
#define MAPPROCESS_RCD "MapProcess"
#define PROCESS_RCD "Process"

//��Ϸ��¼�ĳ�ʼֵ����������������_INI
#define FIRSTSAVE_INI false
#define POSITIONX_INI 63
#define POSITIONY_INI 98
#define MAPPROCESS_INI MAP11
#define PROCESS_INI 0

//����ֱ���
#define JX_RESOLUWID 1136
#define JX_RESOLUHEI 640
#define MAP_RESOLUWID 672
#define MAP_RESOLUHEI 448


//�¼������������¼�����_EVT
//�¼������ִ�����ʽ��վ������A����
//�¼��ڵ�ͼevent��
//վ������stand���ԣ�A������atrg����
//������������������������_ATT
#define STANDTRG_ATT "stand"
#define ATRG_ATT "atrg"

#define ID_ATT "id"



#define ROADSIGN_EVT "road sign"

#define TALKATIVEMAN_EVT "talkative man"
#define NSTR_ATT "nstr"

#define PORTAL_EVT "portal"
#define IDX_ATT "idx"
#define IDY_ATT "idy"

#define CHANGESCENE_EVT "change scene"
#define MAP11 19
#define MAP12 20



#define ANIMATE_EVT "animate"
#define PLACENAME_EVT "place name"

/*�½��¼��Ĳ��裺
1.ѡ��һ��������½�����stand/atrg=�¼�����id=������
2.��event������������ں��ʵ�λ�á�
//3.��Ϊatrg�¼�����wall���Ӧλ�û������
(��Ϊplace name�¼���Ҫ�ڵ�ͼ��information������placenameID����������Ϊidֵ������ֵΪ����)
(��Ϊportal�¼�,����Ϊidx��idy��������Ŀ�ĵص�����)
(��Ϊtalkative man�¼���id�Ƕ�Ӧ��ĸ��'a'������nstrΪ���м��仰������0~9Ϊ���ֵ)
����Ϣ���ڿ�������������ÿ���¼���Ҫһ����һ���Ŀ����
���Ǽ�ʹ�����ֲ�����һ����Ҳ���ǵ�ÿ��һ�������*/
/*��һ�������ǰ������ڶ���㣬��һ��ʼ���ص�ʱ��Ͱ���id
��ʼ�����˺�·��������������ֻ���¼���������id��
��������ͱ���˵������¼��Ĵ�������һɫһ�¼���
Ȼ���һΪ�߶�NPC�Ľ�����������������Ҳ���ԡ�
�������ǿ��԰��˶����ؽ�������һ�㣬����ʾ����Ϊλ��������ʾ��
*/


#define INFORMATION_GRP "information"
#define	TURNINGMAN_OBJ "turningMan"
#define STANDINGMAN_OBJ "standingMan"
#define PLACENAMEID_OBJ "placenameID"

#define NNPC_ATT "nnpc"
#define NPCAX_ATT "npcax"

#define TURNINGMAN_ATTNUM 3
#define STANDINGMAN_ATTNUM 4
#define MARK 100
/*
�½�NPC�Ĳ��裺
1.��NPC����λ����wall�㻭�ϰ�
2.��information��Ķ�Ӧman����������У��½����� npc?x, npc?y��npc?z����npc?{������������nnpc����XML�༭��
3.����н�����NPC����λ����event�㻭��������½�����atrg��id
*/

#define EGLVIEW 0.3
#define ZOOMSTROKELEN 200

typedef enum{kNone=1,kWall=17,kEvent=41}CollisionType;
typedef enum{Down=0,Left=1,Right=2,Up=3}HeroDirection;

#endif /* __APPMACROS_H__ */
