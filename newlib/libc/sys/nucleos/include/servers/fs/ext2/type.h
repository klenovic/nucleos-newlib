#ifndef __SERVERS_FS_EXT2_TYPE_H
#define __SERVERS_FS_EXT2_TYPE_H

#include <nucleos/types.h>

/* On the disk all attributes are stored in little endian format.
 * Inode structure was taken from linux/include/linux/ext2_fs.h.
 */
typedef struct {
	__u16 i_mode;	/* File mode */
	__u16 i_uid;	/* Low 16 bits of Owner Uid */
	__u32 i_size;	/* Size in bytes */
	__u32 i_atime;	/* Access time */
	__u32 i_ctime;	/* Creation time */
	__u32 i_mtime;	/* Modification time */
	__u32 i_dtime;	/* Deletion Time */
	__u16 i_gid;	/* Low 16 bits of Group Id */
	__u16 i_links_count;	/* Links count */
	__u32 i_blocks;	/* Blocks count */
	__u32 i_flags;		/* File flags */

	union {
		struct {
			__u32 l_i_reserved1;
		} linux1;
		struct {
			__u32 h_i_translator;
		} hurd1;
		struct {
			__u32 m_i_reserved1;
		} masix1;
	} osd1;	/* OS dependent 1 */

	__u32 i_block[EXT2_N_BLOCKS];	/* Pointers to blocks */
	__u32 i_generation;		/* File version (for NFS) */
	__u32 i_file_acl;		/* File ACL */
	__u32 i_dir_acl;		/* Directory ACL */
	__u32 i_faddr;			/* Fragment address */

	union {
		struct {
			__u8 l_i_frag;	/* Fragment number */
			__u8 l_i_fsize;	/* Fragment size */
			__u16 i_pad1;
			__u16 l_i_uid_high;	/* these 2 fields    */
			__u16 l_i_gid_high;	/* were reserved2[0] */
			__u32 l_i_reserved2;
		} linux2;
		struct {
			__u8 h_i_frag;		/* Fragment number */
			__u8 h_i_fsize;		/* Fragment size */
			__u16 h_i_mode_high;
			__u16 h_i_uid_high;
			__u16 h_i_gid_high;
			__u32 h_i_author;
		} hurd2;
		struct {
			__u8 m_i_frag;	/* Fragment number */
			__u8 m_i_fsize;	/* Fragment size */
			__u16 m_pad1;
			__u32 m_i_reserved2[2];
		} masix2;
	} osd2;	/* OS dependent 2 */
} d_inode;


/* Part of on disk directory (entry description).
 * It includes all fields except name (since size is unknown.
 * In revision 0 name_len is __u16 (here is structure of rev >= 0.5,
 * where name_len was truncated with the upper 8 bit to add file_type).
 * MIN_DIR_ENTRY_SIZE depends on this structure.
 */
struct ext2_disk_dir_desc {
	__u32 d_ino;
	__u16 d_rec_len;
	__u8 d_name_len;
	__u8 d_file_type;
	char d_name[1];
};

/* Current position in block */
#define CUR_DISC_DIR_POS(cur_desc, base)	((char*)cur_desc - (char*)base)

/* Return pointer to the next dentry */
#define NEXT_DISC_DIR_DESC(cur_desc)	\
	((struct ext2_disk_dir_desc*)((char*)cur_desc + cur_desc->d_rec_len))

/* Return next dentry's position in block */
#define NEXT_DISC_DIR_POS(cur_desc, base)	\
	(cur_desc->d_rec_len + CUR_DISC_DIR_POS(cur_desc, base))


#endif /* __SERVERS_FS_EXT2_TYPE_H */
