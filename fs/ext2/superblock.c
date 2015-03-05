#include <block.h>
#include <kprint.h>
#include "ext2.h"

/* thank visus */
void ext2_trace_super_block(struct ext2_super_block sb)
{
	kprintf(" ext2 super_block trace: \n");
	/*int i=0;*/
	kprintf("s_inodes_count           %x\n",sb.s_inodes_count);
	kprintf("s_blocks_count           %x\n",sb.s_blocks_count);
	kprintf("s_r_blocks_count         %x\n",sb.s_r_blocks_count);
	kprintf("s_free_blocks_count      %x\n",sb.s_free_blocks_count);
	kprintf("s_free_inodes_count      %x\n",sb.s_free_inodes_count);
	kprintf("s_first_data_block       %x\n",sb.s_first_data_block);
	kprintf("s_log_block_size         %x\n",sb.s_log_block_size);
	kprintf("s_log_frag_size          %x\n",sb.s_log_frag_size);
	kprintf("s_blocks_per_group       %x\n",sb.s_blocks_per_group);
	kprintf("s_frags_per_group        %x\n",sb.s_frags_per_group);
	kprintf("s_inodes_per_group       %x\n",sb.s_inodes_per_group);
	kprintf("s_mtime                  %x\n",sb.s_mtime);
	kprintf("s_wtime                  %x\n",sb.s_wtime);
	kprintf("s_mnt_count              %x\n",sb.s_mnt_count);
	kprintf("s_max_mnt_count          %x\n",sb.s_max_mnt_count);
	kprintf("s_magic                  %x (0xef53, should be)\n",sb.s_magic);
	kprintf("s_state                  %x\n",sb.s_state);
	kprintf("s_errors                 %x\n",sb.s_errors);
	kprintf("s_minor_rev_level        %x\n",sb.s_minor_rev_level);
	kprintf("s_lastcheck              %x\n",sb.s_lastcheck);
	kprintf("s_checkinterval          %x\n",sb.s_checkinterval);
	kprintf("s_creator_os             %x\n",sb.s_creator_os);
	kprintf("s_rev_level              %x\n",sb.s_rev_level);
	kprintf("s_def_resuid             %x\n",sb.s_def_resuid);
	/* Just so it will fit on screen, we comment a few out
	kprintf("s_def_resgid             %x\n",sb.s_def_resgid);
	kprintf("s_first_ino              %x\n",sb.s_first_ino);
	kprintf("s_inode_size             %x\n",sb.s_inode_size);
	kprintf("s_block_group_nr         %x\n",sb.s_block_group_nr);
	kprintf("s_feature_compat         %x\n",sb.s_feature_compat);
	kprintf("s_feature_incompat       %x\n",sb.s_feature_incompat);
	kprintf("s_feature_ro_compat      %x\n",sb.s_feature_ro_compat);
	for(i=0;i<16;i++)
		kprintf(" s_uuid[%x]: %x\n",i,sb.s_uuid[i]);
	for(i=0;i<16;i++)
		kprintf(" s_volume_name[%x]: %x\n",i,sb.s_volume_name[i]);
	for(i=0;i<64;i++)
		kprintf(" s_last_mounted[%x]: %x\n",i,sb.s_last_mounted[i]);
	kprintf("s_algorithm_usage_bitmap %x\n",sb.s_algorithm_usage_bitmap);
	kprintf("s_prealloc_blocks        %x\n",sb.s_prealloc_blocks);
	kprintf("s_prealloc_dir_blocks    %x\n",sb.s_prealloc_dir_blocks);
	kprintf("s_padding1               %x\n",sb.s_padding1);
	for(i=0;i<16;i++)
		kprintf(" s_journal_uuid[%x]: %x\n",i,sb.s_journal_uuid[i]);
	kprintf("s_journal_inum           %x\n",sb.s_journal_inum);
	kprintf("s_journal_dev            %x\n",sb.s_journal_dev);
	kprintf("s_last_orphan            %x\n",sb.s_last_orphan);
	for(i=0;i<4;i++)
		kprintf(" s_hash_seed[%x]: %x\n",i,sb.s_hash_seed[i]);
	kprintf("s_def_hash_version       %x\n",sb.s_def_hash_version);
	kprintf("s_reserved_char_pad      %x\n",sb.s_reserved_char_pad);
	kprintf("s_reserved_word_pad      %x\n",sb.s_reserved_word_pad);
	kprintf("s_default_mount_opts     %x\n",sb.s_default_mount_opts);
	kprintf("s_first_meta_bg          %x\n",sb.s_first_meta_bg);
	*/
}

struct ext2_super_block ext2_get_super_block(int disk_num)
{
	struct ext2_super_block sb;
	char * p = (char *)&sb;
	int i;
	for(i=0;i<1024;i++){
		p[i]=read_from_block_device(disk_num,i+1024);
	}
	return sb;
}
