//
//  SKActionMacros.h
//  SKActionMacros
//
//  Created by Ian Arawjo on 10/17/14.
//  Copyright (c) 2014 Ian Arawjo. All rights reserved.
//

#ifndef SKActionMacros_h
#define SKActionMacros_h

/* SKAction Macros (yaaaaaayyyyy!) */
/*  - "Macros are bad, but [SKAction bleh:blah:@[dsfsdf]] is worse!" */
/*  - Why?
 
 Here's a sequence of actions written with SKActionMacros:
 
 sequence(playSoundFile(@"soundFX.wav", NO),
          rotateBy(M_PI/8., .1),
          rotateBy(-M_PI/4.,.2),
          rotateBy(M_PI/8., .1),
          runBlock( [obj runMethodWithArg:arg1]; ))
 
 Equivalent Obj-C code:
 
  [SKAction sequence:@[[SKAction playSoundFileNamed:@"soundFX.wav" waitForCompletion:NO], [SKAction rotateBy:M_PI/8., .1], [SKAction rotateBy:-M_PI/4., .2], [SKAction rotateBy:M_PI/8., .1], [SKAction runBlock:^{ [obj runMethodWithArg:arg1]; }]]];
 
 Need I say more? :)
 
 */

// Creating Actions That Move Nodes
#define moveBy(X,Y,S) [SKAction moveByX:X y:Y duration:S]
#define moveTo(X,Y,S) [SKAction moveTo:CGPointMake(X,Y) duration:S]
#define followPath(P,S) [SKAction followPath:P duration:S]
#define followPathWithSpeed(P, S) [SKAction followPath:P speed:S]

// Creating Actions That Rotate Nodes
#define rotateBy(theta,S) [SKAction rotateByAngle:theta duration:S]
#define rotateTo(theta,S) [SKAction rotateToAngle:theta duration:S]
#define rotateToWithShortestArc(theta, S, A) [SKAction rotateToAngle:theta duration:S shortestUnitArc:A]

// Creating Actions That Change a Node’s Animation Speed
#define speedBy(speed, S) [SKAction speedBy:speed duration:S]
#define speedTo(speed, S) [SKAction speedTo:speed duration:S]

// Creating Actions That Change a Node’s Scale
#define scaleBy(X, S) [SKAction scaleBy:X duration:S]
#define scaleTo(X, S) [SKAction scaleTo:X duration:S]
#define scaleBySeparate(X, Y, S) [SKAction scaleXBy:X y:Y duration:S]
#define scaleToSeparate(X, Y, S) [SKAction scaleXTo:X y:Y duration:S]
#define scaleXTo(X, S) [SKAction scaleXTo:X duration:S]
#define scaleYTo(Y, S) [SKAction scaleYTo:Y duration:S]

// Creating Actions to Show or Hide a Node
#define unhideAction [SKAction unhide]
#define hideAction [SKAction hide]

// Creating Actions That Change a Node’s Transparency
#define fadeIn(S) [SKAction fadeInWithDuration:S]
#define fadeOut(S) [SKAction fadeOutWithDuration:S]
#define fadeAlphaBy(A, S) [SKAction fadeAlphaBy:A duration:S]
#define fadeAlphaTo(A, S) [SKAction fadeAlphaTo:A duration:S]

// Creating Actions That Change a Sprite Node’s Content
#define resizeBy(W,H,S) [SKAction resizeByWidth:W height:H duration:S]
#define resizeTo(W,H,S) [SKAction resizeToWidth:W height:H duration:S]
#define resizeToWidth(W,S) [SKAction resizeToWidth:W duration:S]
#define resizeToHeight(W,S) [SKAction resizeToHeight:W duration:S]
#define setTexture(T) [SKAction setTexture:T]
#define setTextureResize(T, R) [SKAction setTexture:T resize:R]
#define animateWithTextures(S, ...) [SKAction animateWithTextures:@[__VA_ARGS__] timePerFrame:S]
#define animateWithTexturesResize(S, R, R2, ...) [SKAction animateWithTextures:@[__VA_ARGS__] timePerFrame:S resize:R restore:R2]
#define colorizeWithColor(color, blendfactor, S) [SKAction colorizeWithColor:color colorBlendFactor:blendfactor duration:S]
#define colorizeWithBlendFactor(blendfactor, S) [SKAction colorizeWithColorBlendFactor:blendfactor duration:S]

// Creating Actions to Alter the Properties of Field Nodes
/* strengthTo:duration: // I've never used these. If you need them,
 strengthBy:duration:    // add them! I just don't want their macros crowding my space. :)
 falloffTo:duration:
 falloffBy:duration:*/

// Playing Sounds
#define playSoundFile(filename, wait) [SKAction playSoundFileNamed:filename waitForCompletion:wait]

// Removing Nodes from the Scene
#define removeFromParentAction [SKAction removeFromParent]

// Creating Actions That Perform Actions on a Node’s Child
#define runActionOnChild(action, childname) [SKAction runAction:action onChildWithName:childname]

// Creating Actions That Combine or Repeat Other Actions
#define group(...) [SKAction group:@[__VA_ARGS__]]
#define sequence(...) [SKAction sequence:@[__VA_ARGS__]]
#define repeatAction(action, count) [SKAction repeatAction:action count:count]
#define repeatActionForever(action) [SKAction repeatActionForever:action]

// Creating an Action to Introduce a Delay into a Sequence
#define waitForDuration(S) [SKAction waitForDuration:S]
#define waitForDurationWithRange(S, range) [SKAction waitForDuration:S withRange:range]

// Creating Actions to Perform Inverse Kinematic Calculations
/*reachTo:rootNode:duration:        // Never use these either.
 reachTo:rootNode:velocity:          // If you do, I'm sorry!
 reachToNode:rootNode:duration:
 reachToNode:rootNode:velocity:*/

// Creating Custom Actions
#define runBlock(...) [SKAction runBlock:^{__VA_ARGS__}] // magic
#define runBlockOnQueue(Q, ...) [SKAction runBlock:^{__VA_ARGS__} queue:Q]
#define customAction(duration, ...) \
[SKAction customActionWithDuration:duration actionBlock:^(SKNode* node, CGFloat elapsedTime){__VA_ARGS__}]
#define performSelectorOnTarget(sel, target) [SKAction performSelector:sel onTarget:target]

#endif
