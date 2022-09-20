/*
 * File: z_boss_05.c
 * Overlay: ovl_Boss_05
 * Description: Bio Deku Baba
 */

#include "z_boss_05.h"

#define FLAGS (ACTOR_FLAG_1 | ACTOR_FLAG_4)

#define THIS ((Boss05*)thisx)

void Boss05_Init(Actor* thisx, PlayState* play);
void Boss05_Destroy(Actor* thisx, PlayState* play);
void Boss05_Update(Actor* thisx, PlayState* play);
void Boss05_Draw(Actor* thisx, PlayState* play);

void func_809EEDD0(Boss05* this, PlayState* play);
void func_809EEDE8(Boss05* this, PlayState* play);
void func_809EF9BC(Boss05* this, PlayState* play);
void func_809EFAB4(Boss05* this, PlayState* play);
void func_809F00CC(Boss05* this, PlayState* play);
void func_809F010C(Boss05* this, PlayState* play);
void func_809F01CC(Boss05* this, PlayState* play);
void func_809F0244(Boss05* this, PlayState* play);
void func_809F02D0(Boss05* this, PlayState* play);
void func_809F0374(Boss05* this, PlayState* play);
void func_809F0474(Boss05* this, PlayState* play);
void func_809F04C0(Boss05* this, PlayState* play);
void func_809F0538(Boss05* this, PlayState* arg1);
void func_809F0590(Boss05* this, PlayState* play);
void func_809F0650(Boss05* this, PlayState* arg1);
void func_809F06B8(Boss05* this, PlayState* play);
void func_809F0708(Boss05* this, PlayState* play);
void func_809F0780(Boss05* this, PlayState* play);
void func_809F0A0C(Boss05* this, PlayState* play);
void func_809F0A64(Boss05* this, PlayState* play);
void func_809F0ABC(Boss05* this, PlayState* play);
void func_809F0B0C(Boss05* this, PlayState* play);

#include "overlays/ovl_Boss_05/ovl_Boss_05.c"

// static ColliderJntSphElementInit sJntSphElementsInit[2] = {
ColliderJntSphElementInit D_809F1B2C[2] = {
    {
        {
            ELEMTYPE_UNK3,
            { 0xF7CFFFFF, 0x00, 0x08 },
            { 0xF7CFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 15 }, 100 },
    },
    {
        {
            ELEMTYPE_UNK3,
            { 0xF7CFFFFF, 0x00, 0x08 },
            { 0xF7CFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 15 }, 100 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
ColliderJntSphInit D_809F1B74 = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(D_809F1B2C),
    D_809F1B2C, // sJntSphElementsInit,
};

// static ColliderJntSphElementInit sJntSphElementsInit[1] = {
ColliderJntSphElementInit D_809F1B84[1] = {
    {
        {
            ELEMTYPE_UNK3,
            { 0xF7CFFFFF, 0x00, 0x08 },
            { 0xF7CFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 20 }, 100 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
ColliderJntSphInit D_809F1BA8 = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(D_809F1B84),
    D_809F1B84, // sJntSphElementsInit,
};

// static ColliderJntSphElementInit sJntSphElementsInit[1] = {
ColliderJntSphElementInit D_809F1BB8[1] = {
    {
        {
            ELEMTYPE_UNK3,
            { 0xF7CFFFFF, 0x00, 0x08 },
            { 0xF7FFFFFF, 0x00, 0x00 },
            TOUCH_ON | TOUCH_SFX_HARD,
            BUMP_ON,
            OCELEM_ON,
        },
        { 0, { { 0, 0, 0 }, 15 }, 100 },
    },
};

// static ColliderJntSphInit sJntSphInit = {
ColliderJntSphInit D_809F1BDC = {
    {
        COLTYPE_HIT3,
        AT_ON | AT_TYPE_ENEMY,
        AC_ON | AC_TYPE_PLAYER,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_1,
        COLSHAPE_JNTSPH,
    },
    ARRAY_COUNT(D_809F1BB8),
    D_809F1BB8, // sJntSphElementsInit,
};

Color_RGBA8 D_809F1BEC = { 170, 255, 255, 255 };
Color_RGBA8 D_809F1BF0 = { 200, 200, 255, 255 };
Vec3f D_809F1BF4 = { 0.0f, -1.0f, 0.0f };

// static DamageTable sDamageTable = {
DamageTable D_809F1C00 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x0),
    /* Deku Stick     */ DMG_ENTRY(1, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xF),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(3, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(3, 0x0),
    /* Goron punch    */ DMG_ENTRY(2, 0xF),
    /* Sword          */ DMG_ENTRY(1, 0xE),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(1, 0x2),
    /* Ice arrow      */ DMG_ENTRY(1, 0x3),
    /* Light arrow    */ DMG_ENTRY(3, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xF),
    /* Deku spin      */ DMG_ENTRY(1, 0xF),
    /* Deku bubble    */ DMG_ENTRY(3, 0xF),
    /* Deku launch    */ DMG_ENTRY(2, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x0),
    /* Zora barrier   */ DMG_ENTRY(1, 0xF),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xF),
    /* Spin attack    */ DMG_ENTRY(1, 0xF),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0xF),
};

// static DamageTable sDamageTable = {
DamageTable D_809F1C20 = {
    /* Deku Nut       */ DMG_ENTRY(0, 0x1),
    /* Deku Stick     */ DMG_ENTRY(3, 0xF),
    /* Horse trample  */ DMG_ENTRY(0, 0x0),
    /* Explosives     */ DMG_ENTRY(1, 0xF),
    /* Zora boomerang */ DMG_ENTRY(1, 0xF),
    /* Normal arrow   */ DMG_ENTRY(1, 0xF),
    /* UNK_DMG_0x06   */ DMG_ENTRY(0, 0x0),
    /* Hookshot       */ DMG_ENTRY(0, 0x1),
    /* Goron punch    */ DMG_ENTRY(1, 0xF),
    /* Sword          */ DMG_ENTRY(1, 0xF),
    /* Goron pound    */ DMG_ENTRY(1, 0xF),
    /* Fire arrow     */ DMG_ENTRY(2, 0x2),
    /* Ice arrow      */ DMG_ENTRY(2, 0x3),
    /* Light arrow    */ DMG_ENTRY(2, 0x4),
    /* Goron spikes   */ DMG_ENTRY(1, 0xF),
    /* Deku spin      */ DMG_ENTRY(0, 0x1),
    /* Deku bubble    */ DMG_ENTRY(1, 0xF),
    /* Deku launch    */ DMG_ENTRY(2, 0xF),
    /* UNK_DMG_0x12   */ DMG_ENTRY(0, 0x1),
    /* Zora barrier   */ DMG_ENTRY(1, 0xF),
    /* Normal shield  */ DMG_ENTRY(0, 0x0),
    /* Light ray      */ DMG_ENTRY(0, 0x0),
    /* Thrown object  */ DMG_ENTRY(1, 0xF),
    /* Zora punch     */ DMG_ENTRY(1, 0xF),
    /* Spin attack    */ DMG_ENTRY(1, 0xF),
    /* Sword beam     */ DMG_ENTRY(0, 0x0),
    /* Normal Roll    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1B   */ DMG_ENTRY(1, 0x2),
    /* UNK_DMG_0x1C   */ DMG_ENTRY(0, 0x0),
    /* Unblockable    */ DMG_ENTRY(0, 0x0),
    /* UNK_DMG_0x1E   */ DMG_ENTRY(0, 0x0),
    /* Powder Keg     */ DMG_ENTRY(1, 0xF),
};

const ActorInit Boss_05_InitVars = {
    ACTOR_BOSS_05,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_BOSS05,
    sizeof(Boss05),
    (ActorFunc)Boss05_Init,
    (ActorFunc)Boss05_Destroy,
    (ActorFunc)Boss05_Update,
    (ActorFunc)Boss05_Draw,
};

extern AnimationHeader D_060006A4;
extern AnimationHeader D_06000A5C;
extern AnimationHeader D_06000ABC;
extern FlexSkeletonHeader D_060024E0;
extern AnimationHeader D_06002F0C;
extern AnimationHeader D_06003448;
extern AnimatedMaterial D_06006240[];
extern FlexSkeletonHeader D_06006378;
extern AnimationHeader D_06006484;
extern AnimationHeader D_06006E50;
extern AnimationHeader D_06007488;
extern AnimationHeader D_06007908;

void func_809EE4E0(Boss05* this, PlayState* play) {
    Vec3f sp8C;
    Vec3f sp80;
    s32 i;

    SoundSource_PlaySfxAtFixedWorldPos(play, &this->unk18C, 30, NA_SE_EV_ICE_BROKEN);
    for (i = 0; i < 8; i++) {
        sp80.x = randPlusMinusPoint5Scaled(7.0f);
        sp80.z = randPlusMinusPoint5Scaled(7.0f);
        sp80.y = Rand_ZeroFloat(6.0f) + 4.0f;
        sp8C.x = this->unk18C.x + sp80.x;
        sp8C.y = this->unk18C.y + sp80.y;
        sp8C.z = this->unk18C.z + sp80.z;
        EffectSsEnIce_Spawn(play, &sp8C, Rand_ZeroFloat(0.5f) + 0.7f, &sp80, &D_809F1BF4, &D_809F1BEC, &D_809F1BF0, 30);
    }
}

void func_809EE668(s32 elementIndex, ColliderJntSph* collider, Vec3f* pos) {
    collider->elements[elementIndex].dim.worldSphere.center.x = (s32)pos->x;
    collider->elements[elementIndex].dim.worldSphere.center.y = (s32)pos->y;
    collider->elements[elementIndex].dim.worldSphere.center.z = (s32)pos->z;

    collider->elements[elementIndex].dim.worldSphere.radius =
        (s32)(collider->elements[elementIndex].dim.modelSphere.radius * collider->elements[elementIndex].dim.scale);
}

void Boss05_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    Boss05* this = THIS;
    CollisionHeader* colHeader = NULL;

    this->dyna.actor.targetMode = 3;
    this->dyna.actor.colChkInfo.mass = MASS_HEAVY;
    this->dyna.actor.colChkInfo.health = 2;
    this->unk160 = (s32)Rand_ZeroFloat(1000.0f);
    this->unk35C = 1.0f;
    this->dyna.actor.gravity = -0.3f;

    Actor_SetScale(&this->dyna.actor, 0.01f);

    if ((this->dyna.actor.params == 0) || (this->dyna.actor.params == 1)) {
        if (this->dyna.actor.world.rot.z == 0) {
            this->dyna.actor.world.rot.z = 0;
        }

        this->dyna.actor.shape.rot.z = 0;
        this->unk168 = this->dyna.actor.world.rot.z;
        this->dyna.actor.world.rot.z = this->dyna.actor.shape.rot.z;
        this->dyna.actor.colChkInfo.damageTable = &D_809F1C00;

        DynaPolyActor_Init(&this->dyna, 0);
        CollisionHeader_GetVirtual(&sBioBabaLilypadCol, &colHeader);
        this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
        func_809EEDD0(this, play);

        SkelAnime_InitFlex(play, &this->unk268, &D_060024E0, &D_06000ABC, this->unk2AC, this->unk2E8, 10);
        SkelAnime_InitFlex(play, &this->unk3C8, &D_06006378, &D_06006484, this->unk40C, this->unk484, 20);
        this->unk4FC = Animation_GetLastFrame(&D_06006484);

        Collider_InitAndSetJntSph(play, &this->unk1C8, &this->dyna.actor, &D_809F1B74, this->unk1E8);
        Collider_InitAndSetJntSph(play, &this->unk368, &this->dyna.actor, &D_809F1BA8, this->unk388);

        if (Flags_GetClear(play, play->roomCtx.currRoom.num)) {
            this->dyna.actor.params = 2;
            this->actionFunc = func_809EF9BC;
            this->dyna.actor.flags &= ~ACTOR_FLAG_1;
            func_800BC154(play, &play->actorCtx, &this->dyna.actor, ACTORCAT_BG);
        }
    } else if (this->dyna.actor.params == 2) {
        this->actionFunc = func_809EF9BC;

        CollisionHeader_GetVirtual(&sBioBabaLilypadCol, &colHeader);
        this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);

        SkelAnime_InitFlex(play, &this->unk268, &D_060024E0, &D_06000ABC, this->unk2AC, this->unk2E8, 10);
        this->dyna.actor.flags &= ~ACTOR_FLAG_1;
        func_800BC154(play, &play->actorCtx, &this->dyna.actor, ACTORCAT_BG);
    } else if (this->dyna.actor.params == 3) {
        this->actionFunc = func_809EFAB4;
        this->unk198 = 1.0f;

        SkelAnime_InitFlex(play, &this->unk268, &D_060024E0, &D_06000ABC, this->unk2AC, this->unk2E8, 10);
        SkelAnime_InitFlex(play, &this->unk3C8, &D_06006378, &D_06006484, this->unk40C, this->unk484, 0x14);
        this->unk4FC = Animation_GetLastFrame(&D_06006484);

        Collider_InitAndSetJntSph(play, &this->unk1C8, &this->dyna.actor, &D_809F1B74, this->unk1E8);
        Collider_InitAndSetJntSph(play, &this->unk368, &this->dyna.actor, &D_809F1BA8, this->unk388);

        ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
        this->dyna.actor.colChkInfo.damageTable = &D_809F1C00;
    } else if (this->dyna.actor.params == 4) {
        func_809F00CC(this, play);
        this->dyna.actor.colChkInfo.mass = 90;

        SkelAnime_InitFlex(play, &this->unk3C8, &D_06006378, &D_06006484, this->unk40C, this->unk484, 20);

        Collider_InitAndSetJntSph(play, &this->unk368, &this->dyna.actor, &D_809F1BDC, this->unk388);

        ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 30.0f);
        this->dyna.actor.colChkInfo.damageTable = &D_809F1C20;
        this->dyna.actor.flags |= ACTOR_FLAG_10 | ACTOR_FLAG_20;
    } else if (this->dyna.actor.params >= 10) {
        SkelAnime_InitFlex(play, &this->unk3C8, &D_06006378, &D_06006484, this->unk40C, this->unk484, 20);

        this->dyna.actor.gravity = 0.0f;
        this->dyna.actor.world.rot.y = (s32)Rand_ZeroFloat(0x8000);
        this->dyna.actor.speedXZ = Rand_ZeroFloat(3.0f) + 3.0f;
        this->dyna.actor.velocity.y = Rand_ZeroFloat(1.5f) + 1.5f;

        this->unk500 = (s32)randPlusMinusPoint5Scaled(700.0f);
        this->unk502 = (s32)randPlusMinusPoint5Scaled(1500.0f);
        this->unk162[0] = (s32)(Rand_ZeroFloat(30.0f) + 50.0f);

        this->dyna.actor.flags &= ~ACTOR_FLAG_1;
        this->actionFunc = func_809F0B0C;
    }
}

void Boss05_Destroy(Actor* thisx, PlayState* play) {
    Boss05* this = THIS;

    if ((this->dyna.actor.params == 2) || (this->dyna.actor.params == 0) || (this->dyna.actor.params == 1)) {
        DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
    }
}

s32 func_809EECBC(Boss05* this, PlayState* play) {
    if (this->unk16C == 0) {
        s32 var_v0 = 0;
        ColliderJntSphElement* var_v1 = &this->unk1C8.elements[0];

        while (true) {
            var_v0 += 0x40;

            if (var_v1->info.bumperFlags & BUMP_HIT) {
                switch (this->dyna.actor.colChkInfo.damageEffect) {
                    case 2:
                        return 11;
                    case 3:
                        return 20;
                    case 4:
                        return 30;
                    default:
                        return 10;
                }
            }
            var_v1++;

            if (var_v0 == 0x80) {
                if (this->unk368.elements[0].info.bumperFlags & BUMP_HIT) {
                    u8 damage = this->dyna.actor.colChkInfo.damage;
                    this->dyna.actor.colChkInfo.health -= damage;
                    if ((s8)this->dyna.actor.colChkInfo.health <= 0) {
                        Enemy_StartFinishingBlow(play, &this->dyna.actor);
                        return 2;
                    } else {
                        Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_DAMAGE);
                        this->unk16C = 15;
                        this->unk15C = 0;
                        this->unk162[0] = 30;
                        return 0;
                    }
                }

                break;
            }
        }
    }

    return 0;
}

void func_809EEDD0(Boss05* this, PlayState* play) {
    this->actionFunc = func_809EEDE8;
}

Vec3s D_809F1C60[7] = {
    { 0x3200, 0, 0 }, { -0x1E00, 0, 0 }, { -0x1400, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
};
Vec3s D_809F1C8C[7] = {
    { -0x3200, 0, 0 }, { 0, 0, 0 }, { 0x1E00, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
};

void func_809EEDE8(Boss05* this, PlayState* play) {
    s32 var_s3;
    Player* sp108 = GET_PLAYER(play);
    s32 var_v1;
    u8 sp103 = 0;
    Vec3s spD8[7];
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    s32 spB8;
    s32 spB4;
    s32 var_s6;
    s32 var_s7;
    s16 var_s5;
    s16 var_s4;
    f32 spA4;
    f32 var_fv1;
    Vec3f sp94;
    s32 var_s4_2;

    this->dyna.actor.hintId = 8;

    if (this->unk174 == 0) {
        spD4 = 0x3E8;
        spD0 = 0x3E80;
        spCC = 0x7D0;
        spC8 = 0x5DC;
        spC4 = 0x1770;
        spC0 = 0xBB8;
        spBC = 0x514;
        spB8 = 0x5208;
        spB4 = 0xDAC;
        var_s6 = 0xA;
        var_s7 = 0x300;
        if (this->unk16C != 0) {
            spD4 = 0x1B58;
            spCC = 0x1770;
            spC0 = 0x1770;
            spBC = 0x1C84;
            spB4 = 0x1964;
            var_s6 = 1;
            var_s7 = 0x1000;
        }
    } else {
        if (this->unk174 == 3) {
            spD4 = 0x1B58;
            spD0 = 0x3E80;
            spCC = 0x1388;
            spC8 = 0x5DC;
            spC4 = 0x2328;
            spC0 = 0x1388;
            spBC = 0x1C84;
            spB8 = 0x5208;
            spB4 = 0x157C;
            var_s6 = 1;
            var_s7 = 0x1000;
        } else {

            spD4 = spD0 = spCC = spC8 = spC4 = spC0 = spBC = spB8 = spB4 = var_s6 = var_s7 = 0;
        }
    }

    for (var_s3 = 0; var_s3 < 7; var_s3++) {
        if ((this->unk174 == 0) || (this->unk174 == 3)) {
            if (var_s3 < 3) {
                spD8[var_s3].y = 0;
                spD8[var_s3].x = (s32)(Math_SinS((this->unk160 * spD4) + (var_s3 * spD0)) * spCC);
            } else {
                spD8[var_s3].x = 0;
                spD8[var_s3].y = (s32)(Math_SinS((this->unk160 * spC8) + (var_s3 * spC4)) * spC0);
            }

            if ((var_s3 == 4) || (var_s3 == 6)) {
                spD8[var_s3].z = (s32)(Math_SinS((this->unk160 * spBC) + (var_s3 * spB8)) * spB4 * 2.0f);
            } else {
                spD8[var_s3].z = (s32)(Math_SinS((this->unk160 * spBC) + (var_s3 * spB8)) * spB4);
            }
            var_s4 = var_s6;
            var_s5 = var_s7;
        } else {
            if (this->unk174 == 1) {
                var_s6 = 5;
                var_s7 = 0x1000;
                spD8[var_s3].x = D_809F1C60[var_s3].x;
                spD8[var_s3].y = D_809F1C60[var_s3].y;
                spD8[var_s3].z = D_809F1C60[var_s3].z;
            } else if (this->unk174 == 2) {
                var_s6 = 1;
                var_s7 = 0x2000;
                spD8[var_s3].x = D_809F1C8C[var_s3].x;
                spD8[var_s3].y = D_809F1C8C[var_s3].y;
                spD8[var_s3].z = D_809F1C8C[var_s3].z;
            }
            var_s4 = var_s6;
            var_s5 = var_s7;
        }

        Math_ApproachS(&this->unk19E[var_s3].x, spD8[var_s3].x, var_s6, var_s7);
        Math_ApproachS(&this->unk19E[var_s3].y, spD8[var_s3].y, var_s6, var_s7);
        Math_ApproachS(&this->unk19E[var_s3].z, spD8[var_s3].z, var_s6, var_s7);
    }

    // There is some scope for which of var_s4,var_s5 and var_s6,var_s7 are used here
    spA4 = (sp108->actor.world.pos.y - this->dyna.actor.world.pos.y) + 10.0f;
    if (spA4 < 0.0f) {
        Math_ApproachS(&this->dyna.actor.shape.rot.y, this->dyna.actor.yawTowardsPlayer, var_s4, var_s5);
    }

    SkelAnime_Update(&this->unk3C8);
    Math_ApproachF(&this->unk35C, 1.0f, 0.1f, 0.1f);
    if (this->unk15C != 0xA) {
        Math_ApproachS(&this->dyna.actor.shape.rot.x, 0, 0x14, 0x800);
    }

    switch (this->unk15C) { /* irregular */
        case 0:
            this->unk174 = 0;
            this->unk3C8.playSpeed = 1.0f;
            if (spA4 < 0.0f) {
                if (sp108->actor.speedXZ > 10.0f) {
                    var_fv1 = 220.0f;
                } else {
                    var_fv1 = 150.0f;
                }
                if ((this->unk162[0] == 0) && (sqrtf(this->dyna.actor.xyzDistToPlayerSq) <= var_fv1)) {
                    this->unk15C = 1;
                    this->unk162[0] = 0xA;
                }
                this->unk15E = 0;
                // goto block_42;
            } else {

                sp103 = 1;
                if (sqrtf(this->dyna.actor.xyzDistToPlayerSq) <= 40.0f) {
                    this->unk15E++;
                    if (this->unk15E > 0x1E) {
                        this->unk15C = 0xA;
                        this->unk162[0] = 0x1E;
                        Actor_PlaySfxAtPos(&this->dyna.actor, 0x3861U);
                    }
                } else {
                    // block_42:
                    this->unk15E = 0;
                }
            }
            if (!(this->unk160 & 3) && (Rand_ZeroOne() < 0.5f)) {
                Actor_PlaySfxAtPos(&this->dyna.actor, 0x3860U);
            }
            break;

        case 10:
            if (!(this->unk160 & 1)) {
                Actor_PlaySfxAtPos(&this->dyna.actor, 0x3860U);
            }
            this->unk19C = (this->unk162[0] & 1) << 9;
            this->unk174 = 3;
            this->unk3C8.playSpeed = 4.0f;
            Math_ApproachS(&this->dyna.actor.shape.rot.x, -0x8000, 2, 0x2000);
            Math_ApproachS(&this->dyna.actor.shape.rot.y, this->dyna.actor.yawTowardsPlayer, 2, 0x2000);
            if (this->unk162[0] == 0) {
                this->unk15E = 0;
                this->unk15C = 0;
                this->unk162[0] = 0x64;
            }
            if (this->unk162[0] == 0x1B) {
                Math_Vec3f_Copy(&sp94, &this->dyna.actor.world.pos);
                sp94.y += 40.0f;
                EffectSsGSplash_Spawn(play, &sp94, NULL, NULL, 1, 0x7D0);
                Actor_PlaySfxAtPos(&this->dyna.actor, 0x2808U);
            }
            break;

        case 1:
            if (Animation_OnFrame(&this->unk3C8, this->unk4FC)) {
                this->unk3C8.playSpeed = 0.0f;
            }
            this->unk174 = 1;
            if (this->unk162[0] == 0) {
                this->unk15C = 2;
                this->unk162[0] = 0x14;
                Actor_PlaySfxAtPos(&this->dyna.actor, 0x3861U);
            }
            break;

        case 2:
            if (!(this->unk160 & 1)) {
                Actor_PlaySfxAtPos(&this->dyna.actor, 0x3860U);
            }
            this->unk19C = (this->unk162[0] & 1) << 9;
            this->unk3C8.playSpeed = 4.0f;
            Math_ApproachF(&this->unk35C, 1.5f, 1.0f, 0.7f);
            this->unk174 = 2;
            if (this->unk162[0] == 0) {
                this->unk15C = 0;
                this->unk162[0] = 0x1E;
            }
            break;
    }

    var_s4_2 = func_809EECBC(this, play);
    if ((var_s4_2 != 0) || (this->unk168 == 1)) {
        Boss05* temp_v0_6;

        this->dyna.actor.params = 2;
        this->actionFunc = func_809EF9BC;
        this->dyna.actor.flags &= ~1;
        func_800BC154(play, &play->actorCtx, &this->dyna.actor, 1);
        if (this->unk168 != 0) {
            var_s4_2 = 0xA;
        }
        if (var_s4_2 >= 0xA) {
            temp_v0_6 = (Boss05*)Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, 0x12D,
                                                    this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                                    this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x,
                                                    this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, 3);
            if (temp_v0_6 != NULL) {
                Player* temp_v1 = GET_PLAYER(play);
                if (temp_v1->unk_730 == &this->dyna.actor) {
                    temp_v1->unk_730 = &temp_v0_6->dyna.actor;
                    play->actorCtx.targetContext.arrowPointedActor = &temp_v0_6->dyna.actor;
                    play->actorCtx.targetContext.targetedActor = &temp_v0_6->dyna.actor;
                }

                for (var_s3 = 0; var_s3 < 10; var_s3++) {
                    temp_v0_6->unk268.jointTable[var_s3] = this->unk268.jointTable[var_s3];
                }

                for (var_s3 = 0; var_s3 < 20; var_s3++) {
                    temp_v0_6->unk3C8.jointTable[var_s3] = this->unk3C8.jointTable[var_s3];
                }

                Actor_PlaySfxAtPos(&this->dyna.actor, 0x381E);
                if (var_s4_2 >= 0xB) {
                    temp_v0_6->unk188 = var_s4_2 - 0xA;
                }
            }
        } else if (var_s4_2 == 2) {
            for (var_s3 = 0; var_s3 < 2; var_s3++) {
                temp_v0_6 = (Boss05*)Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, 0x12D, this->unk324.x,
                                                        this->unk324.y, this->unk324.z, this->unk330.x, this->unk330.y,
                                                        this->unk330.z, var_s3 + 0xA);
                if (temp_v0_6 != NULL) {

                    for (var_v1 = 0; var_v1 < 20; var_v1++) {
                        temp_v0_6->unk3C8.jointTable[var_v1] = this->unk3C8.jointTable[var_v1];
                    }

                    temp_v0_6->unk162[0] = (s32)(Rand_ZeroFloat(20.0f) + 20.0f);
                }
            }
            Actor_PlaySfxAtPos(&this->dyna.actor, 0x381F);
        }
    }

    if (sp103 == 0) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->unk1C8.base);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->unk368.base);
    }

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->unk1C8.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->unk368.base);
}

void func_809EF9BC(Boss05* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 temp_fv0 = sqrtf(this->dyna.actor.xyzDistToPlayerSq);
    s16 var_a1;

    if ((temp_fv0 < 50.0f) && (player->actor.bgCheckFlags & 1)) {
        var_a1 = (s32)(temp_fv0 * 80.0f);
        var_a1 = CLAMP_MAX(var_a1, 0x7D0);
        // if (var_a1 > 0x7D0) {
        //     var_a1 = 0x7D0;
        // }
        Math_ApproachS(&this->unk178, var_a1, 0x14, 0x7D0);
        Math_ApproachS(&this->unk176, this->dyna.actor.yawTowardsPlayer, 0x14, 0xFA0);
        if (!(this->unk160 & 0xF)) {
            EffectSsGRipple_Spawn(play, &this->dyna.actor.world.pos, 0x1F4, 0x3E8, 0);
        }
    } else {
        Math_ApproachS(&this->unk178, 0, 0x14, 0x100);
    }
}

void func_809EFAB4(Boss05* this, PlayState* play) {
    s32 i;
    Vec3f sp80;
    Vec3f sp74;
    Boss05* temp_v0;
    Player* player;

    Actor_MoveWithGravity(&this->dyna.actor);
    this->dyna.actor.world.pos.y -= 85.0f;
    this->dyna.actor.prevPos.y -= 85.0f;
    Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 20.0f, 50.0f, 40.0f, 0x44U);
    this->dyna.actor.world.pos.y += 85.0f;
    this->dyna.actor.prevPos.y += 85.0f;

    if (this->dyna.actor.bgCheckFlags & 0x20) {
        this->dyna.actor.gravity = -0.3f;
        this->dyna.actor.terminalVelocity = -5.0f;
    } else {
        this->dyna.actor.gravity = -2.0f;
        this->dyna.actor.terminalVelocity = -20.0f;
    }

    if (this->dyna.actor.bgCheckFlags & 0x40) {
        this->dyna.actor.velocity.y = -3.0f;
        this->dyna.actor.gravity = -0.3f;
        this->dyna.actor.terminalVelocity = -5.0f;
        Math_Vec3f_Copy(&sp80, &this->dyna.actor.world.pos);
        sp80.y += 20.0f;
        EffectSsGSplash_Spawn(play, &this->dyna.actor.world.pos, NULL, NULL, 1, 1000);
        this->unk162[2] = 20;
    }

    if (this->unk162[2] != 0) {
        for (i = 0; i < 3; i++) {
            sp74.x = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.x;
            sp74.y = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.y;
            sp74.z = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.z;
            EffectSsBubble_Spawn(play, &sp74, 20.0f, 10.0f, 20.0f, 0.13f);
        }
    }

    if (this->dyna.actor.bgCheckFlags & 1) {
        if ((this->unk189 == 0xA) && (this->unk17A != 0)) {
            this->unk17A = 0;
        }

        Math_ApproachZeroF(&this->unk198, 1.0f, 0.05f);

        if (this->unk198 == 0.0f) {
            temp_v0 = (Boss05*)Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, 0x12D, this->unk324.x,
                                                  this->unk324.y, this->unk324.z, this->unk330.x, this->unk330.y,
                                                  this->unk330.z, 4);

            if (temp_v0 != NULL) {
                player = GET_PLAYER(play);
                if (player->unk_730 == &this->dyna.actor) {
                    player->unk_730 = &temp_v0->dyna.actor;
                    play->actorCtx.targetContext.arrowPointedActor = &temp_v0->dyna.actor;
                    play->actorCtx.targetContext.targetedActor = &temp_v0->dyna.actor;
                }

                for (i = 0; i < 20; i++) {
                    temp_v0->unk3C8.jointTable[i] = this->unk3C8.jointTable[i];
                }

                Actor_PlaySfxAtPos(&temp_v0->dyna.actor, NA_SE_EN_MIZUBABA_TRANSFORM);
            }
            Actor_MarkForDeath(&this->dyna.actor);
        }
    }
}

void func_809EFE50(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    Boss05* this = THIS;
    u8 var_a2 = 0;
    ColliderInfo* temp;

    if ((this->unk16A == 0) && (this->unk368.elements[0].info.bumperFlags & BUMP_HIT)) {
        this->unk368.elements[0].info.bumperFlags &= ~BUMP_HIT;
        temp = this->unk368.elements[0].info.acHitInfo;
        if (temp->toucher.dmgFlags & 0x300000) { // (DMG_NORMAL_SHIELD | DMG_LIGHT_RAY)
            this->unk338 = -12.0f;
            this->unk348 = this->dyna.actor.yawTowardsPlayer;
            this->unk16A = 6;
            return;
        }

        this->unk16A = 0xA;
        this->dyna.actor.speedXZ = 0.0f;
        this->unk338 = -20.0f;
        this->unk348 = this->dyna.actor.yawTowardsPlayer;

        Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_DAMAGE);

        switch (this->dyna.actor.colChkInfo.damageEffect) {
            case 1:
                func_809F0A0C(this, play);
                break;

            case 2:
                this->unk188 = 1;
                var_a2 = 1;
                break;

            case 3:
                func_809F0A64(this, play);
                this->unk188 = 0xA;
                break;

            case 4:
                this->unk188 = 0x14;
                var_a2 = 1;
                break;

            default:
                var_a2 = 1;
                break;
        }

        if (var_a2 != 0) {
            u8 damage; // Probably fake?

            if ((this->actionFunc == func_809F0ABC) && (this->unk189 == 0xA) && (this->unk17A != 0)) {
                func_809EE4E0(this, play);
                this->unk188 = 0;
            }

            damage = this->dyna.actor.colChkInfo.damage;
            this->dyna.actor.colChkInfo.health -= damage;
            if ((s8)this->dyna.actor.colChkInfo.health <= 0) {
                Enemy_StartFinishingBlow(play, &this->dyna.actor);
            }
            func_809F0708(this, play);
            this->unk16C = 0xF;
        }
    }
}

s32 func_809F0014(Boss05* this, PlayState* play) {
    s16 var_v1 = this->dyna.actor.yawTowardsPlayer - this->dyna.actor.shape.rot.y;

    if (ABS_ALT(var_v1) < 0x3000) {
        return true;
    } else {
        return false;
    }
}

void func_809F0058(Boss05* this, PlayState* play) {
    if (func_809F0014(this, play) && (this->dyna.actor.xyzDistToPlayerSq <= SQ(200.0f)) &&
        (fabsf(this->dyna.actor.playerHeightRel) < 70.0f)) {
        func_809F0474(this, play);
    }
}

void func_809F00CC(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F010C;
    Animation_MorphToPlayOnce(&this->unk3C8, &D_06006E50, -5.0f);
}

void func_809F010C(Boss05* this, PlayState* play) {
    SkelAnime_Update(&this->unk3C8);
    Math_ApproachS(&this->dyna.actor.shape.rot.x, 0, 2, 0x400);
    Math_ApproachS(&this->dyna.actor.shape.rot.z, 0, 2, 0x400);
    Math_ApproachF(&this->unk360, 1.0f, 1.0f, 0.5f);
    Math_ApproachF(&this->unk364, 1.0f, 1.0f, 0.14f);
    if (this->unk364 == 1.0f) {
        func_809F01CC(this, play);
    }
}

void func_809F01CC(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F0244;
    Animation_MorphToLoop(&this->unk3C8, &D_06007488, -10.0f);
    this->unk162[0] = (s32)(Rand_ZeroFloat(25.0f) + 25.0f);
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA1_MOUTH);
}

void func_809F0244(Boss05* this, PlayState* play) {
    SkelAnime_Update(&this->unk3C8);
    Math_ApproachZeroF(&this->dyna.actor.speedXZ, 1.0f, 2.5f);
    Math_ApproachS(&this->dyna.actor.shape.rot.x, 0, 2, 0x400);
    Math_ApproachS(&this->dyna.actor.shape.rot.z, 0, 2, 0x400);

    if (this->unk162[0] == 0) {
        func_809F02D0(this, play);
    }

    func_809F0058(this, play);
}

void func_809F02D0(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F0374;
    Animation_MorphToLoop(&this->unk3C8, &D_06007908, 0.0f);
    this->unk162[0] = (s32)(Rand_ZeroFloat(80.0f) + 60.0f);
    this->unk34C = randPlusMinusPoint5Scaled(400.0f) + this->dyna.actor.world.pos.x;
    this->unk354 = randPlusMinusPoint5Scaled(400.0f) + this->dyna.actor.world.pos.z;
    this->unk358 = 0.0f;
}

void func_809F0374(Boss05* this, PlayState* play) {
    f32 sp24;
    f32 sp20;

    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_WALK - SFX_FLAG);
    SkelAnime_Update(&this->unk3C8);
    Math_ApproachF(&this->dyna.actor.speedXZ, 5.0f, 1.0f, 2.0f);
    sp24 = this->unk34C - this->dyna.actor.world.pos.x;
    sp20 = this->unk354 - this->dyna.actor.world.pos.z;
    Math_ApproachS(&this->dyna.actor.world.rot.y, Math_Atan2S(sp24, sp20), 5, (s32)this->unk358);
    Math_ApproachF(&this->unk358, 2000.0f, 1.0f, 100.0f);

    if ((this->unk162[0] == 0) || ((SQ(sp24) + SQ(sp20)) < 2500.0f)) {
        func_809F01CC(this, play);
    }

    func_809F0058(this, play);
}

void func_809F0474(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F04C0;
    Animation_MorphToPlayOnce(&this->unk3C8, &D_06003448, 0.0f);
    this->unk162[0] = 20;
}

void func_809F04C0(Boss05* this, PlayState* play) {
    SkelAnime_Update(&this->unk3C8);
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_VOICE - SFX_FLAG);
    Math_ApproachZeroF(&this->dyna.actor.speedXZ, 1.0f, 2.5f);
    Math_ApproachS(&this->dyna.actor.world.rot.y, this->dyna.actor.yawTowardsPlayer, 5, 0x1000);
    if (this->unk162[0] == 0) {
        func_809F0538(this, play);
    }
}

void func_809F0538(Boss05* this, PlayState* arg1) {
    this->actionFunc = func_809F0590;
    Animation_MorphToLoop(&this->unk3C8, &D_06000A5C, 0.0f);
    this->unk162[0] = 60;
    this->unk358 = 0.0f;
}

void func_809F0590(Boss05* this, PlayState* play) {
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_VOICE - SFX_FLAG);
    SkelAnime_Update(&this->unk3C8);
    Math_ApproachF(&this->dyna.actor.speedXZ, 8.0f, 1.0f, 4.0f);
    Math_ApproachS(&this->dyna.actor.world.rot.y, this->dyna.actor.yawTowardsPlayer, 5, (s32)this->unk358);
    Math_ApproachF(&this->unk358, 4000.0f, 1.0f, 400.0f);
    if ((this->unk162[0] == 0) || (this->dyna.actor.xyzDistToPlayerSq <= 22500.0f)) {
        func_809F0650(this, play);
    }
}

void func_809F0650(Boss05* this, PlayState* arg1) {
    this->actionFunc = func_809F06B8;
    Animation_MorphToPlayOnce(&this->unk3C8, &D_060006A4, 0.0f);
    this->unk4FC = Animation_GetLastFrame(&D_060006A4);
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_ATTACK);
}

void func_809F06B8(Boss05* this, PlayState* play) {
    SkelAnime_Update(&this->unk3C8);
    if (Animation_OnFrame(&this->unk3C8, this->unk4FC)) {
        func_809F01CC(this, play);
    }
}

void func_809F0708(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F0780;
    Animation_MorphToPlayOnce(&this->unk3C8, &D_06002F0C, 0.0f);
    this->unk4FC = Animation_GetLastFrame(&D_060006A4);
    Actor_SetColorFilter(&this->dyna.actor, 0x4000U, 120, 0, 30);
}

// #pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Boss_05/func_809F0780.s")
void func_809F0780(Boss05* this, PlayState* play) {
    s32 i;
    s32 j;
    Vec3f sp7C;
    Boss05* temp_v0;

    SkelAnime_Update(&this->unk3C8);
    if ((s8)this->dyna.actor.colChkInfo.health <= 0) {
        if (Animation_OnFrame(&this->unk3C8, 22.0f)) {
            for (i = 0; i < 14; i++) {
                temp_v0 = (Boss05*)Actor_SpawnAsChild(
                    &play->actorCtx, &this->dyna.actor, play, 0x12D, this->dyna.actor.world.pos.x,
                    this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x,
                    this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, i + 0xA);

                if (temp_v0 != NULL) {
                    for (j = 0; j < 20; j++) {
                        temp_v0->unk3C8.jointTable[j] = this->unk3C8.jointTable[j];
                    }
                }
            }

            for (i = 0; i < 20; i++) {
                sp7C.x = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.x;
                sp7C.y = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.y;
                sp7C.z = randPlusMinusPoint5Scaled(40.0f) + this->dyna.actor.world.pos.z;
                EffectSsBubble_Spawn(play, &sp7C, 20.0f, 10.0f, 20.0f, 0.13f);
            }

            SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 40, 0x381F);
            Actor_MarkForDeath(&this->dyna.actor);
            Item_DropCollectibleRandom(play, NULL, &this->dyna.actor.world.pos, 0xE0);
        }
    } else if (Animation_OnFrame(&this->unk3C8, this->unk4FC)) {
        func_809F0474(this, play);
    }
}

void func_809F0A0C(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F0ABC;
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_DAMAGE);
    this->unk162[0] = 40;
    Actor_SetColorFilter(&this->dyna.actor, 0, 120, 0, 40);
}

void func_809F0A64(Boss05* this, PlayState* play) {
    this->actionFunc = func_809F0ABC;
    Actor_PlaySfxAtPos(&this->dyna.actor, NA_SE_EN_MIZUBABA2_DAMAGE);
    this->unk162[0] = 80;
    Actor_SetColorFilter(&this->dyna.actor, 0, 120, 0, 80);
}

void func_809F0ABC(Boss05* this, PlayState* play) {
    Math_ApproachZeroF(&this->dyna.actor.speedXZ, 1.0f, 2.5f);
    if (this->unk162[0] == 0) {
        func_809F01CC(this, play);
    }
}

void func_809F0B0C(Boss05* this, PlayState* play) {
    Actor_MoveWithGravity(&this->dyna.actor);

    if (this->unk15C == 0) {
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 20.0f, 50.0f, 40.0f, 0x44);
        if (this->dyna.actor.bgCheckFlags & 0x20) {
            this->unk15C = 1;
        } else {
            this->unk15C = 2;
        }
    }

    if (this->unk15C == 1) {
        Math_ApproachF(&this->dyna.actor.velocity.y, 1.0f, 1.0f, 0.1f);
        Math_ApproachZeroF(&this->dyna.actor.speedXZ, 0.5f, 0.5f);
        this->dyna.actor.shape.rot.x += this->unk500;
        this->dyna.actor.shape.rot.y += this->unk502;

        if (this->unk162[0] == 0) {
            Actor_MarkForDeath(&this->dyna.actor);
        }
    } else {
        switch (this->unk15C) {
            case 2:
                this->dyna.actor.velocity.y = Rand_ZeroFloat(3.0f) + 3.0f;
                this->dyna.actor.speedXZ = randPlusMinusPoint5Scaled(5.0f) + 5.0f;
                this->dyna.actor.world.rot.y = (s32)Rand_ZeroFloat(0x10000);
                this->dyna.actor.gravity = -1.0f;
                this->unk15C = 3;
                break;

            case 3:
                Actor_MoveWithGravity(&this->dyna.actor);

                if (this->unk324.y < (this->dyna.actor.floorHeight - 30.0f)) {
                    Actor_MarkForDeath(&this->dyna.actor);
                }
                break;

            default:
                break;
        }
    }
}

void Boss05_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    Boss05* this = (Boss05*)thisx;
    s16 var_v0;

    this->unk160++;

    for (var_v0 = 0; var_v0 < 3; var_v0++) {
        if (this->unk162[var_v0] != 0) {
            this->unk162[var_v0]--;
        }
    }

    if (this->unk16A != 0) {
        this->unk16A--;
    }

    if (this->unk16C != 0) {
        this->unk16C--;
    }
    if (this->unk168 != 0) {
        this->unk168--;
    }

    if (this->unk17A != 0) {
        this->unk17A--;
    }

    this->actionFunc(this, play);

    if (this->dyna.actor.params == 4) {
        Actor_MoveWithGravity(&this->dyna.actor);
        Matrix_RotateYS(this->unk348, MTXMODE_NEW);
        Matrix_MultVecZ(this->unk338, &this->unk33C);
        this->dyna.actor.world.pos.x += this->unk33C.x;
        this->dyna.actor.world.pos.z += this->unk33C.z;
        Math_ApproachZeroF(&this->unk338, 1.0f, 1.0f);
        Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 20.0f, 50.0f, 40.0f, 0x45);
        func_809EFE50(&this->dyna.actor, play);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->unk368.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->unk368.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->unk368.base);
        this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;
    }

    switch (this->unk188) {
        case 0:
            this->unk189 = 0;
            this->unk17A = 0;
            this->unk184 = 0.0f;
            break;

        case 1:
            this->unk189 = 0;
            this->unk17A = 80;
            this->unk184 = 1.0f;
            this->unk188++;
            this->unk17C = 0.0f;
            // fallthrough
        case 2:
            if (this->unk17A == 0) {
                Math_ApproachZeroF(&this->unk184, 1.0f, 0.02f);
                if (this->unk184 == 0.0f) {
                    this->unk188 = 0;
                }
            } else {
                Math_ApproachF(&this->unk17C, 1.0f, 0.1f, 0.5f);
            }
            break;

        case 10:
            this->unk189 = 0xA;
            this->unk17A = 80;
            this->unk184 = 1.0f;
            this->unk188++;
            this->unk17C = 0.0f;
            this->unk180 = 2.0f;
            // fallthrough
        case 11:
            if (this->unk17A == 0) {
                func_809EE4E0(this, play);
                this->unk188 = 0;
            } else {
                Math_ApproachF(&this->unk17C, 1.0f, 1.0f, 0.25f);
                Math_ApproachF(&this->unk180, 1.0f, 0.1f, 0.1f);
            }
            break;

        case 20:
            this->unk189 = 0x14;
            this->unk17A = 80;
            this->unk184 = 1.0f;
            this->unk188++;
            this->unk17C = 0.0f;
            break;

        case 21:
            if (this->unk17A == 0) {
                Math_ApproachZeroF(&this->unk17C, 1.0f, 0.03f);

                if (this->unk17C == 0.0f) {
                    this->unk188 = 0;
                    this->unk184 = 0.0f;
                }
            } else {
                Math_ApproachF(&this->unk17C, 1.0f, 0.5f, 0.5f);
            }
            break;
    }
}

s8 D_809F1CB8[] = { -1, -1, 0, 1, 2, 3, 4, 5, 6, -1, -1, 0 };

s32 func_809F1050(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    Boss05* this = THIS;
    s8 temp_v1;

    if (limbIndex == KREG(32)) {
        if (!(this->unk160 & 3)) {
            *dList = NULL;
        }
        rot->x += KREG(33) * 0x100;
        rot->y += KREG(34) * 0x100;
        rot->z += KREG(35) * 0x100;
    }

    if ((thisx->params == 1) && (limbIndex == 9)) {
        *dList = NULL;
    }

    if (limbIndex == 2) {
        rot->x += this->unk19C;
    }

    temp_v1 = D_809F1CB8[limbIndex];
    if (temp_v1 >= 0) {
        rot->x = rot->x + this->unk19E[temp_v1].x;
        rot->y = rot->y + this->unk19E[temp_v1].y;
        rot->z = rot->z + this->unk19E[temp_v1].z;
    }

    return false;
}

Vec3f D_809F1CC4 = { 0.0f, -1400.0f, 600.0f };

void func_809F1170(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    Boss05* this = THIS;
    MtxF sp3C;
    Vec3f sp30;
    Vec3f sp24;

    if (limbIndex == 4) {
        Matrix_MultVec3f(&D_809F1CC4, &this->unk324);

        if (this->actionFunc == func_809EFAB4) {
            Matrix_MultVec3f(&D_809F1CC4, &this->dyna.actor.focus.pos);
        }

        Matrix_Get(&sp3C);
        Matrix_MtxFToYXZRot(&sp3C, &this->unk330, false);
        this->unk330.x += 0xF00;
    }

    if (limbIndex == 2) {
        Matrix_MultZero(&sp30);
        func_809EE668(0, &this->unk1C8, &sp30);
    }

    if (limbIndex == 3) {
        Matrix_MultVecY(-500.0f, &sp24);
        func_809EE668(1, &this->unk1C8, &sp24);

        if (this->actionFunc == func_809EEDE8) {
            Matrix_MultVecY(1500.0f, &thisx->focus.pos);
        }
    }
}

s32 func_809F1284(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    return false;
}

Vec3f D_809F1CD0 = { 1600.0f, -300.0f, 0.0f };
Vec3f D_809F1CDC = { 700.0f, 0.0f, 0.0f };

Vec3f D_809F2110; // bss

void func_809F12A0(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    Boss05* this = THIS;

    if (limbIndex == 1) {
        Matrix_MultVec3f(&D_809F1CD0, &D_809F2110);
        func_809EE668(0, &this->unk368, &D_809F2110);
        if (thisx->params == 4) {
            Matrix_MultVec3f(&D_809F1CDC, &thisx->focus.pos);
        }
        if (this->unk188 != 0) {
            Matrix_MultVec3f(&D_809F1CDC, &this->unk18C);
            if (this->unk189 == 0) {
                this->unk18C.y -= 15.0f;
            }
        }
    }
}

void func_809F135C(PlayState* play, s32 limbIndex, Actor* thisx) {
    Boss05* this = THIS;

    if ((limbIndex == 2) || (limbIndex == 3)) {
        Matrix_Scale(this->unk35C, 1.0f, this->unk35C, MTXMODE_APPLY);
    }

    if (limbIndex == 1) {
        Matrix_Scale(this->unk360, this->unk360, this->unk360, MTXMODE_APPLY);
    }

    if ((limbIndex >= 4) && (limbIndex < 20)) {
        Matrix_Scale(this->unk364, this->unk364, this->unk364, MTXMODE_APPLY);
    }
}

s32 func_809F1404(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    if ((limbIndex >= 3) && (limbIndex < 9)) {
        *dList = NULL;
    }

    return false;
}

s32 func_809F1430(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    if ((limbIndex == 1) || (limbIndex == 2) || (limbIndex == 9)) {
        *dList = NULL;
    }

    return false;
}

void func_809F1464(PlayState* play, s32 limbIndex, Actor* thisx) {
    Boss05* this = THIS;

    if ((limbIndex >= 3) && (limbIndex < 9)) {
        Matrix_Scale(this->unk198, this->unk198, this->unk198, MTXMODE_APPLY);
    }
}

s32 D_809F1CE8[] = { 2, 3, 1, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19 };

s32 func_809F14AC(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    Boss05* this = THIS;

    if (limbIndex != D_809F1CE8[thisx->params - 10]) {
        *dList = NULL;
    } else if (this->unk15C >= 2) {
        rot->x += this->unk160 * 0x3000;
        rot->y += this->unk160 * 0x1A00;
        rot->z += this->unk160 * 0x2000;
    }
    return false;
}

void func_809F1550(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    Boss05* this = THIS;

    if (limbIndex != D_809F1CE8[thisx->params - 10]) {
        Matrix_MultZero(&this->unk324);
    }
}

void Boss05_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    Boss05* this = THIS;

    OPEN_DISPS(play->state.gfxCtx);

    func_8012C28C(play->state.gfxCtx);

    if (this->actionFunc == func_809EEDE8) {
        SkelAnime_DrawFlexOpa(play, this->unk268.skeleton, this->unk268.jointTable, this->unk268.dListCount,
                              func_809F1050, func_809F1170, &this->dyna.actor);

        if (this->unk16C & 1) {
            POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 0, 0, 255, 900, 1099);
        }

        Matrix_Translate(this->unk324.x, this->unk324.y, this->unk324.z, MTXMODE_NEW);
        Matrix_RotateYS(this->unk330.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->unk330.x, MTXMODE_APPLY);
        Matrix_RotateZS(this->unk330.z, MTXMODE_APPLY);
        Matrix_Scale(this->dyna.actor.scale.x, this->dyna.actor.scale.y, this->dyna.actor.scale.z, MTXMODE_APPLY);

        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(D_06006240));

        SkelAnime_DrawTransformFlexOpa(play, this->unk3C8.skeleton, this->unk3C8.jointTable, this->unk3C8.dListCount,
                                       func_809F1284, func_809F12A0, func_809F135C, &this->dyna.actor);
    } else if (this->dyna.actor.params == 2) {
        Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                         MTXMODE_NEW);
        Matrix_RotateYS(this->unk176, MTXMODE_APPLY);
        Matrix_RotateXS(this->unk178, MTXMODE_APPLY);
        Matrix_RotateYS(-this->unk176, MTXMODE_APPLY);
        Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->dyna.actor.shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);
        Matrix_Scale(this->dyna.actor.scale.x, this->dyna.actor.scale.y, this->dyna.actor.scale.z, MTXMODE_APPLY);

        SkelAnime_DrawFlexOpa(play, this->unk268.skeleton, this->unk268.jointTable, this->unk268.dListCount,
                              func_809F1404, NULL, &this->dyna.actor);
    } else if (this->dyna.actor.params == 3) {
        SkelAnime_DrawTransformFlexOpa(play, this->unk268.skeleton, this->unk268.jointTable, this->unk268.dListCount,
                                       func_809F1430, func_809F1170, func_809F1464, &this->dyna.actor);

        Matrix_Translate(this->unk324.x, this->unk324.y, this->unk324.z, MTXMODE_NEW);
        Matrix_RotateYS(this->unk330.y, MTXMODE_APPLY);
        Matrix_RotateXS(this->unk330.x, MTXMODE_APPLY);
        Matrix_RotateZS(this->unk330.z, MTXMODE_APPLY);
        Matrix_Scale(this->dyna.actor.scale.x, this->dyna.actor.scale.y, this->dyna.actor.scale.z, MTXMODE_APPLY);

        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(D_06006240));

        SkelAnime_DrawTransformFlexOpa(play, this->unk3C8.skeleton, this->unk3C8.jointTable, this->unk3C8.dListCount,
                                       func_809F1284, func_809F12A0, func_809F135C, &this->dyna.actor);

        Actor_DrawDamageEffects(play, &this->dyna.actor, &this->unk18C, 1, this->unk17C, this->unk180, this->unk184,
                                this->unk189);
    } else if (this->dyna.actor.params == 4) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(D_06006240));

        if (this->unk16C & 1) {
            POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, 255, 0, 0, 255, 900, 1099);
        }

        SkelAnime_DrawTransformFlexOpa(play, this->unk3C8.skeleton, this->unk3C8.jointTable, this->unk3C8.dListCount,
                                       func_809F1284, func_809F12A0, func_809F135C, &this->dyna.actor);

        Actor_DrawDamageEffects(play, &this->dyna.actor, &this->unk18C, 1, this->unk17C, this->unk180, this->unk184,
                                this->unk189);
    } else if (this->dyna.actor.params >= 0xA) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(D_06006240));

        SkelAnime_DrawFlexOpa(play, this->unk3C8.skeleton, this->unk3C8.jointTable, this->unk3C8.dListCount,
                              func_809F14AC, func_809F1550, &this->dyna.actor);
    }

    POLY_OPA_DISP = func_801660B8(play, POLY_OPA_DISP);

    CLOSE_DISPS(play->state.gfxCtx);
}
