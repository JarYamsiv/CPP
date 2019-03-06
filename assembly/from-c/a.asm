
main:     file format elf64-x86-64


Disassembly of section .init:

0000000000400540 <_init>:
  400540:	48 83 ec 08          	sub    $0x8,%rsp
  400544:	48 8b 05 ad 0a 20 00 	mov    0x200aad(%rip),%rax        # 600ff8 <_DYNAMIC+0x1e0>
  40054b:	48 85 c0             	test   %rax,%rax
  40054e:	74 05                	je     400555 <_init+0x15>
  400550:	e8 5b 00 00 00       	callq  4005b0 <_ZNSt8ios_base4InitD1Ev@plt+0x10>
  400555:	48 83 c4 08          	add    $0x8,%rsp
  400559:	c3                   	retq   

Disassembly of section .plt:

0000000000400560 <_ZNSt8ios_base4InitC1Ev@plt-0x10>:
  400560:	ff 35 a2 0a 20 00    	pushq  0x200aa2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400566:	ff 25 a4 0a 20 00    	jmpq   *0x200aa4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40056c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400570 <_ZNSt8ios_base4InitC1Ev@plt>:
  400570:	ff 25 a2 0a 20 00    	jmpq   *0x200aa2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400576:	68 00 00 00 00       	pushq  $0x0
  40057b:	e9 e0 ff ff ff       	jmpq   400560 <_init+0x20>

0000000000400580 <__libc_start_main@plt>:
  400580:	ff 25 9a 0a 20 00    	jmpq   *0x200a9a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400586:	68 01 00 00 00       	pushq  $0x1
  40058b:	e9 d0 ff ff ff       	jmpq   400560 <_init+0x20>

0000000000400590 <__cxa_atexit@plt>:
  400590:	ff 25 92 0a 20 00    	jmpq   *0x200a92(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400596:	68 02 00 00 00       	pushq  $0x2
  40059b:	e9 c0 ff ff ff       	jmpq   400560 <_init+0x20>

00000000004005a0 <_ZNSt8ios_base4InitD1Ev@plt>:
  4005a0:	ff 25 8a 0a 20 00    	jmpq   *0x200a8a(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4005a6:	68 03 00 00 00       	pushq  $0x3
  4005ab:	e9 b0 ff ff ff       	jmpq   400560 <_init+0x20>

Disassembly of section .plt.got:

00000000004005b0 <.plt.got>:
  4005b0:	ff 25 42 0a 20 00    	jmpq   *0x200a42(%rip)        # 600ff8 <_DYNAMIC+0x1e0>
  4005b6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

00000000004005c0 <_start>:
  4005c0:	31 ed                	xor    %ebp,%ebp
  4005c2:	49 89 d1             	mov    %rdx,%r9
  4005c5:	5e                   	pop    %rsi
  4005c6:	48 89 e2             	mov    %rsp,%rdx
  4005c9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4005cd:	50                   	push   %rax
  4005ce:	54                   	push   %rsp
  4005cf:	49 c7 c0 90 07 40 00 	mov    $0x400790,%r8
  4005d6:	48 c7 c1 20 07 40 00 	mov    $0x400720,%rcx
  4005dd:	48 c7 c7 b6 06 40 00 	mov    $0x4006b6,%rdi
  4005e4:	e8 97 ff ff ff       	callq  400580 <__libc_start_main@plt>
  4005e9:	f4                   	hlt    
  4005ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004005f0 <deregister_tm_clones>:
  4005f0:	b8 4f 10 60 00       	mov    $0x60104f,%eax
  4005f5:	55                   	push   %rbp
  4005f6:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  4005fc:	48 83 f8 0e          	cmp    $0xe,%rax
  400600:	48 89 e5             	mov    %rsp,%rbp
  400603:	76 1b                	jbe    400620 <deregister_tm_clones+0x30>
  400605:	b8 00 00 00 00       	mov    $0x0,%eax
  40060a:	48 85 c0             	test   %rax,%rax
  40060d:	74 11                	je     400620 <deregister_tm_clones+0x30>
  40060f:	5d                   	pop    %rbp
  400610:	bf 48 10 60 00       	mov    $0x601048,%edi
  400615:	ff e0                	jmpq   *%rax
  400617:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40061e:	00 00 
  400620:	5d                   	pop    %rbp
  400621:	c3                   	retq   
  400622:	0f 1f 40 00          	nopl   0x0(%rax)
  400626:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40062d:	00 00 00 

0000000000400630 <register_tm_clones>:
  400630:	be 48 10 60 00       	mov    $0x601048,%esi
  400635:	55                   	push   %rbp
  400636:	48 81 ee 48 10 60 00 	sub    $0x601048,%rsi
  40063d:	48 c1 fe 03          	sar    $0x3,%rsi
  400641:	48 89 e5             	mov    %rsp,%rbp
  400644:	48 89 f0             	mov    %rsi,%rax
  400647:	48 c1 e8 3f          	shr    $0x3f,%rax
  40064b:	48 01 c6             	add    %rax,%rsi
  40064e:	48 d1 fe             	sar    %rsi
  400651:	74 15                	je     400668 <register_tm_clones+0x38>
  400653:	b8 00 00 00 00       	mov    $0x0,%eax
  400658:	48 85 c0             	test   %rax,%rax
  40065b:	74 0b                	je     400668 <register_tm_clones+0x38>
  40065d:	5d                   	pop    %rbp
  40065e:	bf 48 10 60 00       	mov    $0x601048,%edi
  400663:	ff e0                	jmpq   *%rax
  400665:	0f 1f 00             	nopl   (%rax)
  400668:	5d                   	pop    %rbp
  400669:	c3                   	retq   
  40066a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400670 <__do_global_dtors_aux>:
  400670:	80 3d d1 09 20 00 00 	cmpb   $0x0,0x2009d1(%rip)        # 601048 <__TMC_END__>
  400677:	75 11                	jne    40068a <__do_global_dtors_aux+0x1a>
  400679:	55                   	push   %rbp
  40067a:	48 89 e5             	mov    %rsp,%rbp
  40067d:	e8 6e ff ff ff       	callq  4005f0 <deregister_tm_clones>
  400682:	5d                   	pop    %rbp
  400683:	c6 05 be 09 20 00 01 	movb   $0x1,0x2009be(%rip)        # 601048 <__TMC_END__>
  40068a:	f3 c3                	repz retq 
  40068c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400690 <frame_dummy>:
  400690:	bf 10 0e 60 00       	mov    $0x600e10,%edi
  400695:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400699:	75 05                	jne    4006a0 <frame_dummy+0x10>
  40069b:	eb 93                	jmp    400630 <register_tm_clones>
  40069d:	0f 1f 00             	nopl   (%rax)
  4006a0:	b8 00 00 00 00       	mov    $0x0,%eax
  4006a5:	48 85 c0             	test   %rax,%rax
  4006a8:	74 f1                	je     40069b <frame_dummy+0xb>
  4006aa:	55                   	push   %rbp
  4006ab:	48 89 e5             	mov    %rsp,%rbp
  4006ae:	ff d0                	callq  *%rax
  4006b0:	5d                   	pop    %rbp
  4006b1:	e9 7a ff ff ff       	jmpq   400630 <register_tm_clones>

00000000004006b6 <main>:
  4006b6:	55                   	push   %rbp
  4006b7:	48 89 e5             	mov    %rsp,%rbp
  4006ba:	b8 2a 00 00 00       	mov    $0x2a,%eax
  4006bf:	5d                   	pop    %rbp
  4006c0:	c3                   	retq   

00000000004006c1 <_Z41__static_initialization_and_destruction_0ii>:
  4006c1:	55                   	push   %rbp
  4006c2:	48 89 e5             	mov    %rsp,%rbp
  4006c5:	48 83 ec 10          	sub    $0x10,%rsp
  4006c9:	89 7d fc             	mov    %edi,-0x4(%rbp)
  4006cc:	89 75 f8             	mov    %esi,-0x8(%rbp)
  4006cf:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  4006d3:	75 27                	jne    4006fc <_Z41__static_initialization_and_destruction_0ii+0x3b>
  4006d5:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
  4006dc:	75 1e                	jne    4006fc <_Z41__static_initialization_and_destruction_0ii+0x3b>
  4006de:	bf 49 10 60 00       	mov    $0x601049,%edi
  4006e3:	e8 88 fe ff ff       	callq  400570 <_ZNSt8ios_base4InitC1Ev@plt>
  4006e8:	ba 40 10 60 00       	mov    $0x601040,%edx
  4006ed:	be 49 10 60 00       	mov    $0x601049,%esi
  4006f2:	bf a0 05 40 00       	mov    $0x4005a0,%edi
  4006f7:	e8 94 fe ff ff       	callq  400590 <__cxa_atexit@plt>
  4006fc:	90                   	nop
  4006fd:	c9                   	leaveq 
  4006fe:	c3                   	retq   

00000000004006ff <_GLOBAL__sub_I_main>:
  4006ff:	55                   	push   %rbp
  400700:	48 89 e5             	mov    %rsp,%rbp
  400703:	be ff ff 00 00       	mov    $0xffff,%esi
  400708:	bf 01 00 00 00       	mov    $0x1,%edi
  40070d:	e8 af ff ff ff       	callq  4006c1 <_Z41__static_initialization_and_destruction_0ii>
  400712:	5d                   	pop    %rbp
  400713:	c3                   	retq   
  400714:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40071b:	00 00 00 
  40071e:	66 90                	xchg   %ax,%ax

0000000000400720 <__libc_csu_init>:
  400720:	41 57                	push   %r15
  400722:	41 56                	push   %r14
  400724:	41 89 ff             	mov    %edi,%r15d
  400727:	41 55                	push   %r13
  400729:	41 54                	push   %r12
  40072b:	4c 8d 25 c6 06 20 00 	lea    0x2006c6(%rip),%r12        # 600df8 <__frame_dummy_init_array_entry>
  400732:	55                   	push   %rbp
  400733:	48 8d 2d ce 06 20 00 	lea    0x2006ce(%rip),%rbp        # 600e08 <__init_array_end>
  40073a:	53                   	push   %rbx
  40073b:	49 89 f6             	mov    %rsi,%r14
  40073e:	49 89 d5             	mov    %rdx,%r13
  400741:	4c 29 e5             	sub    %r12,%rbp
  400744:	48 83 ec 08          	sub    $0x8,%rsp
  400748:	48 c1 fd 03          	sar    $0x3,%rbp
  40074c:	e8 ef fd ff ff       	callq  400540 <_init>
  400751:	48 85 ed             	test   %rbp,%rbp
  400754:	74 20                	je     400776 <__libc_csu_init+0x56>
  400756:	31 db                	xor    %ebx,%ebx
  400758:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40075f:	00 
  400760:	4c 89 ea             	mov    %r13,%rdx
  400763:	4c 89 f6             	mov    %r14,%rsi
  400766:	44 89 ff             	mov    %r15d,%edi
  400769:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40076d:	48 83 c3 01          	add    $0x1,%rbx
  400771:	48 39 eb             	cmp    %rbp,%rbx
  400774:	75 ea                	jne    400760 <__libc_csu_init+0x40>
  400776:	48 83 c4 08          	add    $0x8,%rsp
  40077a:	5b                   	pop    %rbx
  40077b:	5d                   	pop    %rbp
  40077c:	41 5c                	pop    %r12
  40077e:	41 5d                	pop    %r13
  400780:	41 5e                	pop    %r14
  400782:	41 5f                	pop    %r15
  400784:	c3                   	retq   
  400785:	90                   	nop
  400786:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40078d:	00 00 00 

0000000000400790 <__libc_csu_fini>:
  400790:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400794 <_fini>:
  400794:	48 83 ec 08          	sub    $0x8,%rsp
  400798:	48 83 c4 08          	add    $0x8,%rsp
  40079c:	c3                   	retq   
