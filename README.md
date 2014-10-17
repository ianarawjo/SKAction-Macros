SKAction-Macros
===============

Readable macros for chaining SKActions (and not losing your mind!).

###Why?

Here's a sequence of actions written with SKActionMacros:
 
```
 sequence(playSoundFile(@"soundFX.wav", NO),
          rotateBy(M_PI/8., .1),
          rotateBy(-M_PI/4.,.2),
          rotateBy(M_PI/8., .1),
          runBlock( [obj runMethodWithArg:arg1]; ))
```
 
Equivalent Obj-C code:

```
  [SKAction sequence:@[[SKAction playSoundFileNamed:@"soundFX.wav" waitForCompletion:NO], [SKAction rotateBy:M_PI/8., .1], [SKAction rotateBy:-M_PI/4., .2], [SKAction rotateBy:M_PI/8., .1], [SKAction runBlock:^{ [obj runMethodWithArg:arg1]; }]]];
```
 
Need I say more? :)

####Credits

Created by Ian Arawjo (https://twitter.com/RottenCartridge). Licensed under MIT license.
