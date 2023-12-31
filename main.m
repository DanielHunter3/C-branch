#import <Foundation/Foundation.h>
#include <math.h>

@interface Math : NSObject

@property double x;
@property double y;

(instancetype)initWithX:(double)x andY:(double)y;
(double)mathOperationsWithSymbol:(NSString *)symbol;
@end

@implementation Math

(instancetype)initWithX:(double)x andY:(double)y {
self = [super init];
if (self) {
_x = x;
_y = y;
}
return self;
}

(double)mathOperationsWithSymbol:(NSString )symbol {
if ([symbol isEqualToString:@"+"]) return _x + _y;
else if ([symbol isEqualToString:@"-"]) return _x - _y;
else if ([symbol isEqualToString:@""]) return _x * _y;
else if ([symbol isEqualToString:@"/"]) {
if (_y == 0.0) {
NSLog(@"The Y is 0");
abort();
}
else return _x / _y;
}
else if ([symbol isEqualToString:@"^"]) return powf(_x, _y);
else {
NSLog(@"This is not math operation: %@", symbol);
abort();
}
}

@end

int main(int argc, const char * argv[]) {
@autoreleasepool {
double x = 0.0, y = 0.0;
NSString *symbol;

    NSLog(@"Enter a first number: ");
    scanf("%lf", &x);
    
    NSLog(@"Enter a math symbol: ");
    char buffer[100];
    scanf("%s", buffer);
    symbol = [NSString stringWithUTF8String:buffer];
    
    NSArray *vec = @[@"+", @"-", @"*", @"/", @"^"];
    
    NSString *result = @"";
    BOOL isBool = [vec containsObject:symbol];
    
    if (!isBool) {
        NSLog(@"This is not math operation: %@", symbol);
        abort();
    }
    
    NSLog(@"Enter a second number: ");
    scanf("%lf", &y);
    
    Math *math = [[Math alloc] initWithX:x andY:y];
    NSLog(@"Result: %lf", [math mathOperationsWithSymbol:result]);
}
return 0;

}
