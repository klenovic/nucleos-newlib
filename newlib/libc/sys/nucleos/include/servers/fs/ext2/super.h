/* Super block table. The root file system and every mounted file system
 * has an entry here. The entry holds information about the sizes of the bit
 * maps and inodes.
 *
 * A super_block slot is free if s_dev == NO_DEV.
 *
 */

#ifndef __SERVERS_FS_EXT2_SUPER_H
#define __SERVERS_FS_EXT2_SUPER_H

#include <nucleos/types.h>
#include <servers/fs/ext2/type.h>

/* super_block (on-disk part) was taken from linux/include/linux/ext2_fs.h */
struct ext2_super_block {
	__u32 s_inodes_count;		/* Inodes count */
	__u32 s_blocks_count;		/* Blocks count */
	__u32 s_r_blocks_count;		/* Reserved blocks count */
	__u32 s_free_blocks_count;	/* Free blocks count */
	__u32 s_free_inodes_count;	/* Free inodes count */
	__u32 s_first_data_block;	/* First Data Block */
	__u32 s_log_block_size;		/* Block size */
	__u32 s_log_frag_size;		/* Fragment size */
	__u32 s_blocks_per_group;	/* # Blocks per group */
	__u32 s_frags_per_group;	/* # Fragments per group */
	__u32 s_inodes_per_group;	/* # Inodes per group */
	__u32 s_mtime;			/* Mount time */
	__u32 s_wtime;			/* Write time */
	__u16 s_mnt_count;		/* Mount count */
	__u16 s_max_mnt_count;		/* Maximal mount count */
	__u16 s_magic;			/* Magic signature */
	__u16 s_state;			/* File system state */
	__u16 s_errors;			/* Behaviour when detecting errors */
	__u16 s_minor_rev_level;	/* minor revision level */
	__u32 s_lastcheck;		/* time of last check */
	__u32 s_checkinterval;		/* max. time between checks */
	__u32 s_creator_os;		/* OS */
	__u32 s_rev_level;		/* Revision level */
	__u16 s_def_resuid;		/* Default uid for reserved blocks */
	__u16 s_def_resgid;		/* Default gid for reserved blocks */
	/*
	 * These fields are for EXT2_DYNAMIC_REV superblocks only.
	 *
	 * Note: the difference between the compatible feature set and
	 * the incompatible feature set is that if there is a bit set
	 * in the incompatible feature set that the kernel doesn't
	 * know about, it should refuse to mount the filesystem.
	 *
	 * e2fsck's requirements are more strict; if it doesn't know
	 * about a feature in either the compatible or incompatible
	 * feature set, it must abort and not try to meddle with
	 * things it doesn't understand...
	 */
	__u32 s_first_ino;		/* First non-reserved inode */
	__u16 s_inode_size;		/* size of inode structure */
	__u16 s_block_group_nr;		/* block group # of this superblock */
	__u32 s_feature_compat;		/* compatible feature set */
	__u32 s_feature_incompat;	/* incompatible feature set */
	__u32 s_feature_ro_compat;	/* readonly-compatible feature set */
	__u8 s_uuid[16];		/* 128-bit uuid for volume */
	char s_volume_name[16];		/* volume name */
	char s_last_mounted[64];	/* directory where last mounted */
	__u32 s_algorithm_usage_bitmap;	/* For compression */

	/*
	 * Performance hints.  Directory preallocation should only
	 * happen if the EXT2_COMPAT_PREALLOC flag is on.
	 */
	__u8 s_prealloc_blocks;		/* Nr of blocks to try to preallocate*/
	__u8 s_prealloc_dir_blocks;	/* Nr to preallocate for dirs */
	__u16 s_padding1;

	/*
	 * Journaling support valid if EXT3_FEATURE_COMPAT_HAS_JOURNAL set.
	 */
	__u8 s_journal_uuid[16];	/* uuid of journal superblock */
	__u32 s_journal_inum;		/* inode number of journal file */
	__u32 s_journal_dev;		/* device number of journal file */
	__u32 s_last_orphan;		/* start of list of inodes to delete */
	__u32 s_hash_seed[4];		/* HTREE hash seed */
	__u8 s_def_hash_version;	/* Default hash version to use */
	__u8 s_reserved_char_pad;
	__u16 s_reserved_word_pad;
	__u32 s_default_mount_opts;
	__u32 s_first_meta_bg;		/* First metablock block group */
	__u32 s_reserved[190];		/* Padding to the end of the block */

};


#endif /* __SERVERS_FS_EXT2_SUPER_H */
